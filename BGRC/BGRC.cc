/*
 * BGRC.cpp
 *
 *  Created on: Jul 5, 2015
 *      Author: Adel Khosravi
 */

#include <BGRC/BGRC.h>

Define_Module(BGRC);

void BGRC::startup() {
    totalNodes = getParentModule()->getParentModule()->par("numNodes");
    maxIteration = (int) par("maxIteration");
    randomSeed = (int) par("randomSeed");
    helloEx = (int) par("helloEx");
    txInterval_perNode = (double) par("NepacketSpacing") / 1000.0;  // in ms
    itSpacing = (double) par("ItSpacing")/1000.0;

    isDelayed = (int) par("isDelayed");
    numDelayed = (int) par("numDelayed");
    delayms = (int) par("delayms");
    transDelay = (int) par("transDelay");
    softDelay = (int) par("softDelay");
    softDelayRate = (double) ((double) (par("softDelayRate")) / 100.0);
    rcvRand = (double) genk_dblrand(randomSeed);
    neibErr = (int) par("neibErr");
    neibErrRate = (double) par("neibErrRate");

    packetSize = (int) par("packetSize");
    packetSpacing = (double) (10.0
            * ((double) genk_dblrand(randomSeed) / 10.0 + 1.1));

    txInterval_total = (double) (txInterval_perNode * (totalNodes+1));
    startTxTime = (double) txInterval_perNode * (self+1);
    maxIteration = (int) par("maxIteration");
    rnd = (bool) par("rnd");

    numNe = 0;
    data.p = 0.0;
    stateCn = 0;
    realAvg = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        data.z[i] = 0;
        data.y[i] = 0;
        data.adj[i] = 0;
    }

    if (helloEx == 1) {
        setTimer(NEIGHNOR_DISC, startTxTime);
        setTimer(SENSOR_READ, txInterval_total  + itSpacing);
    } else {
        setTimer(SENSOR_READ, packetSpacing);
    }
}

void BGRC::timerFiredCallback(int index) {
    BGRCPacket* cPck = new BGRCPacket("Consensus Packet", APPLICATION_PACKET);
    BGRCData tmpData;
    switch (index) {
    case NEIGHNOR_DISC:
        toNetworkLayer(createGenericDataPacket(0.0, ndPack, packetSize),
        BROADCAST_NETWORK_ADDRESS);
        break;
    case SENSOR_READ:
        if (helloEx == 1) {
            if (neibErr == 1) {
            	numNe += (int) (neibErrRate * numNe);
            	numNe = (numNe < 0)?0:numNe;	
            }
            data.p = (double) 1.0 / (1.0 + numNe);
            	//numNe += (int) (neibErrRate * numNe);
               // numNe += (int) (neibErrRate * (genk_dblrand(randomSeed) - 0.5));
            
        } else {
            data.p = (double) genk_dblrand(randomSeed);
        }
        requestSensorReading();
        break;
    case NEXT_ITERATION:
        if (stateCn < maxIteration) {
            setTimer(BROADCAST_DATA, startTxTime);
            setTimer(NEXT_ITERATION, txInterval_total);
        }
        break;
    case BROADCAST_DATA:
        totalMsg[stateCn]++;
        stateCn++;
        data.y[stateCn] = (double) (data.p * data.y[stateCn - 1]);
        data.z[stateCn] = (double) (data.p * data.z[stateCn - 1]);
        data.x[stateCn] = (double) data.y[stateCn] / data.z[stateCn];
        tmpData.yVal = data.y[stateCn];
        tmpData.zVal = data.z[stateCn];
        cPck->setSequenceNumber(stateCn);
        cPck->setEData(tmpData);
        cPck->setData(1.0);
        toNetworkLayer(cPck, BROADCAST_NETWORK_ADDRESS);
        break;
    }

}

void BGRC::fromNetworkLayer(ApplicationPacket *genericPacket,
        const char *source, double rssi, double lqi) {
    if (genericPacket->getData() == 1.0) {
        if ((softDelay == 1 && isDelayed == 1) && self < numDelayed) {
            if (softDelayRate <= rcvRand) {
                BGRCPacket* cPck = check_and_cast<BGRCPacket*>(genericPacket);
                BGRCData tmpData = cPck->getEData();
                data.y[stateCn] += (double) tmpData.yVal;
                data.z[stateCn] += (double) tmpData.zVal;
            }

        } else {
            BGRCPacket* cPck = check_and_cast<BGRCPacket*>(genericPacket);
            BGRCData tmpData = cPck->getEData();
            stateCn++;
            data.y[stateCn] = (double) (data.y[stateCn - 1] + tmpData.yVal);
            data.z[stateCn] = (double) (data.z[stateCn - 1] + tmpData.zVal);
            data.x[stateCn] = (double) (data.y[stateCn] / data.z[stateCn]);

        }

    } else if (genericPacket->getData() == 0.0) {
        data.adj[atoi(source)] = 1;
        data.neList[numNe++] = atoi(source);
    }
}

void BGRC::handleSensorReading(SensorReadingMessage *rcvReading) {

    double sensedValue; 
    if(rnd) 
    		sensedValue = rcvReading->getSensedValue();
    else 
    		sensedValue = (double) (self/50.0);
    data.y[stateCn] = sensedValue;
    data.z[stateCn] = 1.0;
    data.x[stateCn] = sensedValue;
    realAvg += sensedValue;

    if ((isDelayed == 1 && self < numDelayed) && transDelay == 1) {
        startTxTime = (double) (txInterval_perNode) * (self + 1);
        txInterval_total = (double) (delayms *(txInterval_perNode * (totalNodes + 1)));
        //setTimer(BROADCAST_DATA, startTxTime);
        setTimer(NEXT_ITERATION, (double) (txInterval_total));
    } else {
        startTxTime = (double) (txInterval_perNode) * (self+1);
        txInterval_total = (double) (txInterval_perNode * (totalNodes+1));
        setTimer(BROADCAST_DATA, startTxTime);
        setTimer(NEXT_ITERATION, txInterval_total);
    }


}

void BGRC::finishSpecific() {
    declareOutput("sArray");
    declareOutput("wArray");	
    declareOutput("xArray");
    declareOutput("adj");
    declareOutput("totalPck");
    int tmp = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        collectOutput("adj", i, "value", data.adj[i]);
    }

    for (int i = 0; i <= stateCn; i++) {
        collectOutput("xArray", i, "value", data.x[i]);
        collectOutput("sArray", i, "value", (data.y[i]<0.001)?0:data.y[i]);
        collectOutput("wArray", i, "value", (data.z[i]<0.001)?0:data.z[i]);
        collectOutput("totalPck", i, "value", totalMsg[i]);
        tmp += totalMsg[i];
    }
    if (self == 0) {
        realAvg = (double) (realAvg / totalNodes);
        trace() << "Average is : " << (double) realAvg;
    }
    trace() << "Consensus is : " << (double) data.x[stateCn] << "total pck : " << tmp;
}



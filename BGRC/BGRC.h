/*
 * BGRC.h
 *
 *  Created on: Jul 5, 2015
 *      Author: Adel Khosravi
 */
#ifndef BGRC_H_
#define BGRC_H_
#define MAX_SIZE 20000

#include "VirtualApplication.h"
#include <BGRC/BGRCPacket_m.h>
//#include <vector>

enum Timer_Enum {
    NEIGHNOR_DISC = 1, BROADCAST_DATA = 2, SENSOR_READ = 3, NEXT_ITERATION = 4,
};

struct dataTable {

    double p;
    int neList[MAX_SIZE];
    int adj[MAX_SIZE];
    double y[MAX_SIZE];
    double z[MAX_SIZE];
    double x[MAX_SIZE];
};

static double realAvg;
static long totalMsg[MAX_SIZE];

class BGRC: public VirtualApplication {
private:
    dataTable data;

    int totalNodes;
    int maxIteration;
    int helloEx;
    int ndPack; //neighbor discovery packet counter
    int numNe;  //num of neighbors counter
    int stateCn;

    int isDelayed;
    bool rnd;
    int numDelayed;
    int delayms;
    int transDelay;
    int softDelay;
    int neibErr;
    double neibErrRate;
    double softDelayRate;
    double rcvRand;
    int packetSize;
    int randomSeed;
    double packetSpacing;
    double itSpacing;
    double txInterval_perNode;
    double txInterval_total;
    double startTxTime;

protected:
    void startup();
    void finishSpecific();
    void fromNetworkLayer(ApplicationPacket *, const char *, double, double);
    void handleSensorReading(SensorReadingMessage *);
    void timerFiredCallback(int);
};

#endif /* BGRC_H_ */


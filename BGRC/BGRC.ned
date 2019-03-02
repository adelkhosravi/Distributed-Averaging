package node.application.BGRC;

simple BGRC like node.application.iApplication
{
    parameters:
        string applicationID = default("BGRC");
        bool collectTraceInfo = default(true);
        int priority = default(1);
        int packetHeaderOverhead = default(8);	// in bytes
        int constantDataPayload = default(12);	// in bytes

        int maxIteration = default(10);		// iteration number	
        int NepacketSpacing = default(100);	// in ms. hello message exchange time between each packet
        int ItSpacing = default(500);
        int packetSize = default(8);	// in bytes
        int randomSeed = default(1);

        int isDelayed = default(0);	// is nodes have delay?
        int transDelay = default(0);
        int softDelay = default(0);
        int numDelayed = default(0);
        int delayms = default(2);
        int softDelayRate = default(0);
        int neibErr = default(0);
        double neibErrRate = default(0.0);
        bool rnd = default(true);

        int helloEx = default(1); 		// 1: hello message phase. 0: no hello message phase and default aij and djk is used

    gates:
        output toCommunicationModule;
        output toSensorDeviceManager;
        input fromCommunicationModule;
        input fromSensorDeviceManager;
        input fromResourceManager;

}

cplusplus {{
#include "ApplicationPacket_m.h"
}}

class ApplicationPacket;

struct BGRCData {
	double yVal;			
	double zVal;	
} 

packet BGRCPacket extends ApplicationPacket {
	BGRCData eData;
}


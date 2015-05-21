//
//  ITUSAT_XBEE.h
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 10/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#ifndef __ITUSAT_ENERGIA__ITUSAT_XBEE__
#define __ITUSAT_ENERGIA__ITUSAT_XBEE__

#include "Energia.h"
#include <inttypes.h>

#define XBEE_BEGIN_ENVELOPE 0x01
#define XBEE_CLOSE_ENVELOPE 0x02

class ITUSAT_XBEE {
    
    
public:
    ITUSAT_XBEE();
    
    void begin();
    void addEnvelope(uint8_t);
    void addData(int);
    void addData(float);
    void addData(double);
    void addCRC();
    void sendTelemetry();
    
};

#endif /* defined(__ITUSAT_ENERGIA__ITUSAT_XBEE__) */

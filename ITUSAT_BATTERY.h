//
//  ITUSAT_BATTERY.h
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 10/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#ifndef __ITUSAT_ENERGIA__ITUSAT_BATTERY__
#define __ITUSAT_ENERGIA__ITUSAT_BATTERY__
#include <inttypes.h>
#include "Energia.h"

#define BATTERY_REFERENCEBIRIM (3.20/4096)

class ITUSAT_BATTERY {
    
    
public:
    ITUSAT_BATTERY();
    
    float   batteryVoltage;
    int     rawVoltage;
    uint8_t selectedPin;
    void    begin(uint8_t);
    float   readVoltage();
    
};


#endif /* defined(__ITUSAT_ENERGIA__ITUSAT_BATTERY__) */

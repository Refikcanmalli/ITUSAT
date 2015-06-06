//
//  ITUSAT_LIGHT.h
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 20/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#ifndef __ITUSAT_ENERGIA__ITUSAT_LIGHT__
#define __ITUSAT_ENERGIA__ITUSAT_LIGHT__

#include <inttypes.h>
#include <Energia.h>

#define LIGHT_REFERENCEBIRIM    (3.30/4096)
#define LIGHT_TRESHOLD          (500)
#define RESISTOR_10K            0x01
//#define RESISTOR_100K         0x02

class ITUSAT_LIGHT {
    
    
public:
    ITUSAT_LIGHT();
    float   rawLight;
    float   realLight;
    uint8_t selectedPin;
    void    begin(uint8_t);
    uint8_t readLight();
    
};

#endif /* defined(__ITUSAT_ENERGIA__ITUSAT_LIGHT__) */

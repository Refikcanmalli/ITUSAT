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

#define LIGHT_REFERENCEBIRIM (3.00/1024)

class ITUSAT_LIGHT {
    
    
public:
    ITUSAT_LIGHT();
    float   rawLight;
    float   realLight;
    uint8_t selectedPin;
    void    begin(uint8_t);
    float   readLight();
    
};

#endif /* defined(__ITUSAT_ENERGIA__ITUSAT_LIGHT__) */

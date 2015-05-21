//
//  ITUSAT_LM35.h
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 20/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#ifndef __ITUSAT_ENERGIA__ITUSAT_LM35__
#define __ITUSAT_ENERGIA__ITUSAT_LM35__

#include <inttypes.h>
#include "Energia.h"


class ITUSAT_LM35 {
    
    
public:
    ITUSAT_LM35();
    float   rawTemperature;
    float   realTemperature;
    uint8_t selectedPin;
    void    begin(uint8_t);
    float   readTemperature();
    
};

#endif /* defined(__ITUSAT_ENERGIA__ITUSAT_LM35__) */

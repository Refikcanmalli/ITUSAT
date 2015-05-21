//
//  ITUSAT_NTC.h
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 10/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#ifndef __ITUSAT_ENERGIA__ITUSAT_NTC__
#define __ITUSAT_ENERGIA__ITUSAT_NTC__

#include <inttypes.h>
#include "Energia.h"

// Nominal temperature value for the thermistor
#define TERMISTORNOMINAL 10000
// Nominl temperature depicted on the datasheet
#define TEMPERATURENOMINAL 25
// Beta value for our thermistor
#define BCOEFFICIENT 3977
// Value of the series resistor
#define SERIESRESISTOR 100000

class ITUSAT_NTC {
    
    
public:
    ITUSAT_NTC();
    int     rawTemperature;
    float   realTemperature;
    uint8_t selectedPin;
    void    begin(uint8_t);
    float   readTemperature();
    
};

#endif /* defined(__ITUSAT_ENERGIA__ITUSAT_NTC__) */

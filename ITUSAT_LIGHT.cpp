//
//  ITUSAT_LIGHT.cpp
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 20/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#include "ITUSAT_LIGHT.h"



ITUSAT_LIGHT::ITUSAT_LIGHT()
{
    
}

void ITUSAT_LIGHT::begin(uint8_t pin)
{
    selectedPin = pin;
    
}

uint8_t ITUSAT_LIGHT::readLight()
{
#ifdef RESISTOR_10K

    rawLight =  analogRead(selectedPin);    // read the input pin
    realLight = (LIGHT_REFERENCEBIRIM) * rawLight ;
    if (realLight>=LIGHT_TRESHOLD)
    {
        return 1;
    }
    else
    {
        return 0;
    }
#elif RESISTOR_100K
    rawLight =  analogRead(selectedPin);    // read the input pin
    realLight = (LIGHT_REFERENCEBIRIM) * rawLight ;
    if (realLight>=LIGHT_TRESHOLD)
    {
        return 1;
    }
    else
    {
        return 0;
    }

#endif

    
}
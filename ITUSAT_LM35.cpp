//
//  ITUSAT_LM35.cpp
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 20/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#include "ITUSAT_LM35.h"


ITUSAT_LM35::ITUSAT_LM35()
{
    
}

void ITUSAT_LM35::begin(uint8_t pin)
{
    selectedPin = pin;
    
}

float ITUSAT_LM35::readTemperature()
{
    rawTemperature = analogRead(selectedPin);
    // Convert the thermal stress value to resistance
    rawTemperature =  (3.3 * rawTemperature * 100.0)/1024.0;
    return rawTemperature;
    
}
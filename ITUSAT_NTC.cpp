//
//  ITUSAT_NTC.cpp
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 10/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#include "ITUSAT_NTC.h"


ITUSAT_NTC::ITUSAT_NTC()
{
    
}

void ITUSAT_NTC::begin(uint8_t pin)
{
    selectedPin = pin;
    
}

float ITUSAT_NTC::readTemperature()
{
    rawTemperature = analogRead(selectedPin);
    // Convert the thermal stress value to resistance
    rawTemperature = 1023 / rawTemperature - 1;
    rawTemperature = SERIESRESISTOR / rawTemperature;
    
    //Calculate temperature using the Beta Factor equation
    realTemperature = rawTemperature / TERMISTORNOMINAL;     // (R/Ro)
    realTemperature = log(realTemperature); // ln(R/Ro)
    realTemperature /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
    realTemperature += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
    realTemperature = 1.0 / realTemperature;                 // Invert the value
    realTemperature -= 273.15;                         // Convert it to Celsius}
    
    return realTemperature;

}
//
//  ITUSAT_BATTERY.cpp
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 10/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#include "ITUSAT_BATTERY.h"


ITUSAT_BATTERY::ITUSAT_BATTERY()
{
    
}

void ITUSAT_BATTERY::begin(uint8_t pin)
{
    selectedPin = pin;

}

float ITUSAT_BATTERY::readVoltage()
{
    
    rawVoltage =  analogRead(selectedPin);    // read the input pin
    batteryVoltage = (BATTERY_REFERENCEBIRIM) * rawVoltage ;
    return batteryVoltage * 2;
}
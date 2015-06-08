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

int ITUSAT_LIGHT::readLight()
{
    rawLight =  analogRead(selectedPin);    // read the input pin
    //realLight = (LIGHT_REFERENCEBIRIM) * rawLight ;
    realLight = rawLight;
    return realLight;
    

    
}
//
//  ITUSAT_XBEE.cpp
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 10/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#include "ITUSAT_XBEE.h"


ITUSAT_XBEE::ITUSAT_XBEE()
{
    
}

void ITUSAT_XBEE::begin()
{

}

void ITUSAT_XBEE::addEnvelope(uint8_t mode)
{
    if (mode == 0)
        
        Serial.print("!(");
    
    else
        
        Serial.print(")!");
        
}

void ITUSAT_XBEE::addData(int data)
{
    Serial.print("\"");
    Serial.print(data);
    Serial.print("\",");
}

void ITUSAT_XBEE::addData(float data)
{
    Serial.print("\"");
    Serial.print(data);
    Serial.print("\",");
}

void ITUSAT_XBEE::addData(double data)
{
    Serial.print("\"");
    Serial.print(data);
    Serial.print("\",");
}

void ITUSAT_XBEE::addCRC(uint8_t crcData)
{
    Serial.print("\"");
    Serial.print(crcData);
    Serial.print("\"");
    

}
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
    Serial1.begin(9600);
}

void ITUSAT_XBEE::addEnvelope(uint8_t mode)
{
    if (mode == 0)
        
        Serial1.print("!(");
    
    else
        
        Serial1.print(")!\n");
        
}

void ITUSAT_XBEE::addData(int data)
{
    Serial1.print("\"");
    Serial1.print(data);
    Serial1.print("\",");
}

void ITUSAT_XBEE::addData(float data)
{
    Serial1.print("\"");
    Serial1.print(data);
    Serial1.print("\",");
}

void ITUSAT_XBEE::addData(double data)
{
    Serial1.print("\"");
    Serial1.print(data);
    Serial1.print("\",");
}

void ITUSAT_XBEE::addData(unsigned long data)
{
    Serial1.print("\"");
    Serial1.print(data);
    Serial1.print("\",");
}

void ITUSAT_XBEE::addCRC(uint8_t crcData)
{
    Serial1.print("\"");
    Serial1.print(crcData);
    Serial1.print("\"");
    

}
//
//  ITUSAT_EEPROM.cpp
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 03/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#include "ITUSAT_EEPROM.h"
#include "Wire.h"

ITUSAT_EEPROM::ITUSAT_EEPROM()
{
    
}

void ITUSAT_EEPROM::begin()
{
    Wire.begin();
}


uint8_t ITUSAT_EEPROM::readEEPROMState()
{
    return readData(MEM_EEPROM_STATE);
}

uint8_t ITUSAT_EEPROM::readHours()
{
    return readData(MEM_TIME_HOURS);
}

uint8_t ITUSAT_EEPROM::readMinutes()
{
    return readData(MEM_TIME_MINUTES);
}


uint8_t ITUSAT_EEPROM::readSeconds()
{
    return readData(MEM_TIME_SECONDS);
}

uint8_t ITUSAT_EEPROM::readMissionState()
{
    return readData(MEM_MISSION_STATE);
}
uint8_t ITUSAT_EEPROM::readCurrentFswState()
{
    return readData(MEM_CURRENT_FSW);
}

uint8_t ITUSAT_EEPROM::readPreviousFswState()
{
    return readData(MEM_PREVIOUS_FSW);
}





void  ITUSAT_EEPROM::writeEEPROMState(uint8_t data)
{
    writeData(MEM_EEPROM_STATE, data);
}

void  ITUSAT_EEPROM::writeHours(uint8_t data)
{
    writeData(MEM_TIME_HOURS, data);
}

void  ITUSAT_EEPROM::writeMinutes(uint8_t data)
{
    writeData(MEM_TIME_MINUTES, data);
}

void  ITUSAT_EEPROM::writeSeconds(uint8_t data)
{
    writeData(MEM_TIME_SECONDS, data);
}

void    ITUSAT_EEPROM::writeMissionState(uint8_t data)
{
    writeData(MEM_MISSION_STATE, data);
    // ALIHAN <3 IRMAK
}

void ITUSAT_EEPROM::writeCurrentFswState(uint8_t data)
{
    writeData(MEM_CURRENT_FSW, data);
}

void ITUSAT_EEPROM::writePreviousFswState(uint8_t data)
{
     writeData(MEM_PREVIOUS_FSW, data);
}

/////////////////////////////////////////////////////








/////////////////////////////////////////////////////



uint8_t ITUSAT_EEPROM::readData(int address)
{
    byte rdata = 0xFF;
    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write((int)(address >> 8));   // MSB
    Wire.write((int)(address & 0xFF)); // LSB
    Wire.endTransmission();
    
    Wire.requestFrom(EEPROM_ADDRESS,1);
    
    if (Wire.available()) rdata = Wire.read();
    
    return rdata;
}

void ITUSAT_EEPROM::writeData(int address, uint8_t value)
{
    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write((int)(address >> 8));   // MSB
    Wire.write((int)(address & 0xFF)); // LSB
    Wire.write(value);
    Wire.endTransmission();
    delay(5);
}

ITUSAT_EEPROM EEPROM;
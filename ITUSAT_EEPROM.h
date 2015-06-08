//
//  ITUSAT_EEPROM.h
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 03/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#ifndef __ITUSAT_EEPROM__
#define __ITUSAT_EEPROM__

#include "Energia.h"
#include <inttypes.h>
#define EEPROM_ADDRESS           0x50
#define EEPROM_SIZE              1024000


#define MEM_EEPROM_STATE         0x00
#define MEM_MISSION_STATE        1
#define MEM_PREVIOUS_FSW         2
#define MEM_TIME_HOURS           3
#define MEM_TIME_MINUTES         4
#define MEM_TIME_SECONDS         5
#define MEM_CURRENT_FSW          6
#define MEM_LAST_ADDRESS         10
#define MEM_MISSION_TIME         14
#define MEM_BASE_ALTITUDE        18


#define MEM_FSW_ROCKET_DEPLOY    25
#define MEM_FSW_SEPERATION       26
#define MEM_FSW_LANDED           27

#define MEM_DEPLOYED_TELEMETRY   30
#define MEM_SEPERATED_TELEMETRY  100

#define MEM_TELEMETRY_START      150


#define MISSION_FINISHED         0xFF
#define MISSION_STARTED          0x11
#define MISSION_READY            0xCC
#define MISSION_ERASE            0xAA
#define EEPROM_STATE_LOCK        0xFF
#define EEPROM_STATE_UNLOCK      0x11

#define SIZE_FLOAT               4
#define SIZE_INT                 2
#define SIZE_LONG                4
#define SIZE_CHAR                1


class ITUSAT_EEPROM
{
public:
    ITUSAT_EEPROM();
    byte temp[SIZE_FLOAT];
    void begin();
    
    uint8_t readPreviousFswState();
    uint8_t readCurrentFswState();
    uint8_t readEEPROMState();
    uint8_t readHours();
    uint8_t readMinutes();
    uint8_t readSeconds();
    uint8_t readMissionState();
    
    
    void    writePreviousFswState(uint8_t);
    void    writeCurrentFswState(uint8_t);
    void    writeEEPROMState(uint8_t);
    void    writeHours(uint8_t);
    void    writeMinutes(uint8_t);
    void    writeSeconds(uint8_t);
    void    writeMissionState(uint8_t);

    
    
    
    uint8_t testEEPROM();
    uint8_t readData(int);
    void    writeData(int, uint8_t);
    

    
    //EXP
    
    template <class T> int writeAnything(int ee, const T& value)
    {
        const byte* p = (const byte*)(const void*)&value;
        unsigned int i;
        for (i = 0; i < sizeof(value); i++)
            writeData(ee++, *p++);
        return i;
    }
    
    template <class T> int readAnything(int ee, T& value)
    {
        byte* p = (byte*)(void*)&value;
        unsigned int i;
        for (i = 0; i < sizeof(value); i++)
            *p++ = readData(ee++);
        return i;
    }
    
};

//extern ITUSAT_EEPROM EEPROM;


#endif /* defined(__ITUSAT_ENERGIA__ITUSAT_EEPROM__) */

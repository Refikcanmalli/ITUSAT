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


#define MEM_ACTIVE_STATE         0x00
#define MEM_EEPROM_LOCK          0x01
#define MEM_FSW_STATE            0x02
#define MEM_LAST_ADDRESS         0x03
#define MEM_TIME_HOURS           0x04
#define MEM_TIME_MINUTES         0x05
#define MEM_TIME_SECONDS         0x06
#define MEM_TEST_EEPROM          0x07

#define MISSION_LOCK_EEPROM      0xFF
#define MISSION_UNLOCK_EEPROM    0x11

#define SIZE_FLOAT               4
#define SIZE_INT                 2
#define SIZE_LONG                4
#define SIZE_CHAR                1


class ITUSAT_EEPROM
{
public:
    byte temp[SIZE_FLOAT];
    
    uint8_t readFswState();
    uint8_t readActiveState();
    uint8_t readHours();
    uint8_t readMinutes();
    uint8_t readSeconds();
    uint8_t readLock();
    
    void    writeFswState(uint8_t);
    void    writeActiveState(uint8_t);
    void    writeHours(uint8_t);
    void    writeMinutes(uint8_t);
    void    writeSeconds(uint8_t);
    void    writeLock(uint8_t);
    
    
    uint8_t testEEPROM();
    uint8_t readData(int);
    void writeData(int, uint8_t);
    
    //EXP
    float   readFloat(int);
    long    readLong(int);
    int     readInt(int);
    char    readChar(int);
    
    void    writeLong(int,long);
    void    writeInt(int,int);
    void    writeChar(int,char);
    void    writeFloat(int,float);
    
};

extern ITUSAT_EEPROM EEPROM;


#endif /* defined(__ITUSAT_ENERGIA__ITUSAT_EEPROM__) */

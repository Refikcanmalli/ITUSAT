//
//  ITUSAT_CORE.cpp
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 10/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#include "ITUSAT_CORE.h"



void ITUSAT_CORE::startModules()

{

#ifdef EEPROMLOCKENABLED
    
    eepromLockCheck = eeprom.readLock();
    if (eepromLockCheck != LOCK_EEPROM) {
        FSWstatus = 1;
        eeprom.writeFswState(FSWstatus);
        eeprom.writeLock(LOCK_EEPROM);
    }
#endif
#ifndef EEPROMLOCKENABLED
    
    FSWstatus = 0;
    
#endif
    rtc.begin();
    uint8_t u8Status = rtc.get();
    
    if (!u8Status)
    {
        timeofStart = rtc.time.hour*3600 + rtc.time.min*60 +  rtc.time.sec;
    }
    thermistor1.begin(THERMISTOR1_PIN);
    thermistor2.begin(THERMISTOR2_PIN);
    battery.begin(BATTERY_PIN);
    bmp.initialize();

}

int ITUSAT_CORE::rtc_millis()
{
    int dummy;
    uint8_t u8Status = rtc.get();
    if (!u8Status)
    {
       dummy = rtc.time.hour*3600 + rtc.time.min*60 +  rtc.time.sec;
    }
    
    return dummy - timeofStart;

    
}
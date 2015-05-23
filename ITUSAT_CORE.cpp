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
    // Genel baslangic
    eepromLockCheck = eeprom.readLock();
    rtc.begin();
    uint8_t u8Status = rtc.get();
    
    if (!u8Status)
    {
        timeofStart = rtc.time.hour*3600 + rtc.time.min*60 +  rtc.time.sec;
    }
    // Mission daha once baslamis mi kontrolu
    if (eepromLockCheck != MISSION_LOCK_EEPROM) {
        // FSW sifirla ilk baslangic saatini kaydet
        FSWstatus = 1;
        eeprom.writeFswState(FSWstatus);
        eeprom.writeLock(MISSION_LOCK_EEPROM);
        eeprom.writeHours(rtc.time.hour);
        eeprom.writeMinutes(rtc.time.min);
        eeprom.writeSeconds(rtc.time.sec);
    }
    else
    {
        // Power gitmis
        timeofStart = eeprom.readHours()*3600 + eeprom.readMinutes()*60 +  eeprom.readSeconds();
        FSWstatus = eeprom.readFswState();
    }
    
    //thermistor1.begin(THERMISTOR1_PIN);
    //thermistor2.begin(THERMISTOR2_PIN);
    tempIN.begin(PIN_LM35_1);
    tempOUT.begin(PIN_LM35_2);
    battery.begin(PIN_BATTERY);
    light.begin(PIN_LIGHT);
    bmp.initialize();
    adxl.initialize();

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
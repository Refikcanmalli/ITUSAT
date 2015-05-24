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

unsigned long ITUSAT_CORE::rtc_millis()
{
    
    unsigned long  dummy;
    uint8_t u8Status = rtc.get();
    if (!u8Status)
    {
       dummy = rtc.time.hour*3600 + rtc.time.min*60 +  rtc.time.sec;
    }
    
    return dummy - timeofStart;

}

void ITUSAT_CORE::rtc_print_time(char *dateString)
{

    uint8_t u8Status = rtc.get();
    
    if (!u8Status)
    {
        sprintf(dateString, "%4u-%02u-%02u %02u:%02u:%02u (DOW: %u, CAL: 0x%02x).",
                2000 + rtc.time.year, rtc.time.month, rtc.time.day, rtc.time.hour,
                rtc.time.min, rtc.time.sec, rtc.time.dow, rtc.time.cal);
        Serial.println(dateString);
    }
    else
    {
        Serial.print("Unable to get current time due to I2C error 0x");
        Serial.print(u8Status, HEX);
        Serial.println(".");
    }

    
}

void ITUSAT_CORE::rtc_set_calibration()
{
    
    uint8_t x, y, u8Status;
    
    Serial.println("Enter new calibration value in hex (skip 0x):");
    while (Serial.available() < 2)
    {
    }
    
    x = Serial.read(); // cal: upper nibble
    if (BOUND(x, '0', '9'))
    {
        x -= '0';
    }
    else if (BOUND(x, 'A', 'F'))
    {
        x -= ('A' - 10);
    }
    else if (BOUND(x, 'a', 'f'))
    {
        x -= ('a' - 10);
    }
    else
    {
        x = 0;
    }
    
    y = Serial.read(); // cal: lower nibble
    if (BOUND(y, '0', '9'))
    {
        y -= '0';
    }
    else if (BOUND(y, 'A', 'F'))
    {
        y -= ('A' - 10);
    }
    else if (BOUND(y, 'a', 'f'))
    {
        y -= ('a' - 10);
    }
    else
    {
        y = 0;
    }
    
    u8Status = rtc.setCalibration((x << 4) + y);
    if (u8Status)
    {
        Serial.print("Unable to set calibration value due to I2C error 0x");
        Serial.print(u8Status, HEX);
        Serial.println(".");
    }


    
    
}
void ITUSAT_CORE::rtc_set_time()
{
    
    uint8_t x, y, u8Status;
    ITUSAT_RTC::time_t newtime;
    
    Serial.println("Enter new time in format (dow is Sun, Mon, ... Sat):");
    Serial.println("yyyy-mm-dd hh:mm:ss dow");
    while (Serial.available() < 22)
    {
    }
    
    x = Serial.read(); // discard digit
    x = Serial.read(); // discard digit
    x = Serial.read(); // year: tens digit
    y = Serial.read(); // year: ones digit
    newtime.year = 10 * (x - '0') + (y - '0');
    
    x = Serial.read(); // discard spacer
    x = Serial.read(); // month: tens digit
    y = Serial.read(); // month: ones digit
    newtime.month = 10 * (x - '0') + (y - '0');
    
    x = Serial.read(); // discard spacer
    x = Serial.read(); // day: tens digit
    y = Serial.read(); // day: ones digit
    newtime.day = 10 * (x - '0') + (y - '0');
    
    x = Serial.read(); // discard spacer
    x = Serial.read(); // hour: tens digit
    y = Serial.read(); // hour: ones digit
    newtime.hour = 10 * (x - '0') + (y - '0');
    
    x = Serial.read(); // discard spacer
    x = Serial.read(); // min: tens digit
    y = Serial.read(); // min: ones digit
    newtime.min = 10 * (x - '0') + (y - '0');
    
    x = Serial.read(); // discard spacer
    x = Serial.read(); // sec: tens digit
    y = Serial.read(); // sec: ones digit
    newtime.sec = 10 * (x - '0') + (y - '0');
    
    x = Serial.read(); // discard spacer
    x = Serial.read(); // dow: 1st character
    y = Serial.read(); // dow: 2nd character
    
    switch(x)
    {
        case 'S':
        case 's':
            if (y == 'U' or y == 'u')
            {
                newtime.dow = 1;
            }
            
            if (y == 'A' or y == 'a')
            {
                newtime.dow = 7;
            }
            break;
            
        case 'M':
        case 'm':
            newtime.dow = 2;
            break;
            
        case 'T':
        case 't':
            if (y == 'U' or y == 'u')
            {
                newtime.dow = 3;
            }
            
            if (y == 'H' or y == 'h')
            {
                newtime.dow = 5;
            }
            break;
            
        case 'W':
        case 'w':
            newtime.dow = 4;
            break;
            
        case 'F':
        case 'f':
            newtime.dow = 6;
            break;
    }
    
    Serial.flush();
    
    u8Status = rtc.set(&newtime);
    if (u8Status)
    {
        Serial.print("Unable to set time due to I2C error 0x");
        Serial.print(u8Status, HEX);
        Serial.println(".");
    }


}

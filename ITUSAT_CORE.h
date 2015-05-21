//
//  ITUSAT_CORE.h
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 10/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#ifndef __ITUSAT_ENERGIA__ITUSAT_CORE__
#define __ITUSAT_ENERGIA__ITUSAT_CORE__

#include "Energia.h"
#include "ITUSAT_EEPROM.h"
#include "ITUSAT_RTC.h"
#include "ITUSAT_NTC.h"
#include "BMP085.h"
#include "ADXL345.h"
#include "ITUSAT_XBEE.h"
#include "ITUSAT_CAMERA.h"
#include "ITUSAT_BATTERY.h"
#include "ITUSAT_LM35.h"
#include "I2Cdev.h"
#include "ITUSAT_GPS.h"

#define THERMISTOR1_PIN         P1_5
#define THERMISTOR2_PIN         P1_6
#define BATTERY_PIN             P1_3
#define LM35_PIN1               P1_3
#define LM35_PIN2               P1_3
#define GPS_PIN                 P1_3

class ITUSAT_CORE
{
public:
    
    ITUSAT_RTC rtc;
    ITUSAT_EEPROM eeprom;
    ITUSAT_CAMERA camera;
    ITUSAT_NTC thermistor1,thermistor2;
    ITUSAT_LM35 tempIN,tempOUT;
    ITUSAT_BATTERY battery;
    ADXL345 accelometer;
    BMP085 bmp;
    
    uint8_t     FSWstatus;
    uint8_t     eepromLockCheck ;
    float       insideTemperature;
    float       outsideTemperature;
    float       altitude;
    int         timeofStart ;
    float       accX;
    float       accY;
    float       accZ;
    
    void        startModules();
    uint8_t     calculateCRC();
    int         rtc_millis();

};

extern ITUSAT_CORE Core;




#endif /* defined(__ITUSAT_ENERGIA__ITUSAT_CORE__) */

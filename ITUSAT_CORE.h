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
#include "ITUSAT_LIGHT.h"
#include "BMP085.h"
#include "ADXL345.h"
#include "ITUSAT_XBEE.h"
#include "ITUSAT_CAMERA.h"
#include "ITUSAT_BATTERY.h"
#include "ITUSAT_LM35.h"
#include "I2Cdev.h"
#include "ITUSAT_GPS.h"

#define PIN_THERMISTOR1         P1_5
#define PIN_THERMISTOR2         P1_6
#define PIN_BATTERY             P1_3
#define PIN_LM35_1              P1_3
#define PIN_LM35_2              P1_3
#define PIN_GPS                 P1_3
#define PIN_LIGHT               P1_6



class ITUSAT_CORE
{
public:
    
    ITUSAT_RTC rtc;
    ITUSAT_EEPROM eeprom;
    ITUSAT_CAMERA camera;
    ITUSAT_NTC thermistor1,thermistor2;
    ITUSAT_LIGHT light;
    ITUSAT_LM35 tempIN,tempOUT;
    ITUSAT_BATTERY battery;
    ADXL345 adxl;
    BMP085 bmp;
    
    uint8_t         FSWstatus;
    uint8_t         eepromLockCheck ;
    float           insideTemperature;
    float           outsideTemperature;
    float           altitude;
    unsigned long   timeofStart ;
    unsigned long   timeNow ;
    float           accX;
    float           accY;
    float           accZ;
    
    void            startModules();
    uint8_t         calculateCRC();
    unsigned long   rtc_millis();
    void            rtc_set_time();
    void            rtc_print_time(char *);
    void            rtc_set_calibration();

};







#endif /* defined(__ITUSAT_ENERGIA__ITUSAT_CORE__) */

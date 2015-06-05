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
#include "ADA_BMP085.h"
#include "ADXL345.h"
#include "ITUSAT_XBEE.h"
#include "ITUSAT_CAMERA.h"
#include "ITUSAT_BATTERY.h"
#include "ITUSAT_LM35.h"
#include "I2Cdev.h"
#include "ITUSAT_GPS.h"
#include "ITUSAT_BUZZER.h"

#define TEAM_NUMBER             3806

#define PIN_THERMISTOR1         P1_5
#define PIN_THERMISTOR2         P1_6
#define PIN_GPS                 P1_3


#define PIN_LED1                P1_2
#define PIN_LED2                P1_3
#define PIN_LED3                P1_4
#define PIN_BUZZER              P2_5
#define PIN_LM35_IN             P7_0
#define PIN_LM35_OUT            P6_5
#define PIN_BATTERY             P6_6
#define PIN_LIGHT               P6_4



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
    ITUSAT_XBEE xbee;
    ITUSAT_BUZZER buzzer;
    Adafruit_BMP085 bmp_ada;
    ADXL345 adxl;
    BMP085 bmp;
    
    int             loopCounter;
    uint8_t         FSWstatus;
    uint8_t         eepromLockCheck ;
    float           insideTemperature;
    float           outsideTemperature;
    float           altitude;
    float           batteryVoltage;
    unsigned long   timeofStart ;
    unsigned long   timeNow ;
    float           accX;
    float           accY;
    float           accZ;
    
    void            startModules();
    void            warnReady();
    uint8_t         calculateCRC();
    unsigned long   rtc_millis();
    void            rtc_set_time();
    void            rtc_print_time(char *);
    void            rtc_set_calibration();
    void            toggle(uint8_t,int);
    void            beginLEDS();
    uint8_t         decideFSW();
    void            sendTelemetry();
    void            saveTelemetry();

};







#endif /* defined(__ITUSAT_ENERGIA__ITUSAT_CORE__) */

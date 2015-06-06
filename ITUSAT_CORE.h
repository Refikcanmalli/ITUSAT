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
#include "Servo.h"
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
#include "ITUSAT_SERVO.h"

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
#define PIN_SERVO               39
#define PIN_CAMERALED           P1_5



class ITUSAT_CORE
{
public:
    
    struct Telemetry{
        char            startByte;
        unsigned long   time;
        float           altitude;
        float           insideTemperature;
        float           outsideTemperature;
        float           batteryVoltage;
        uint8_t         FSWstatus;
        float           accX;
        float           accY;
        float           accZ;
        char            stopByte;
    
    } telemetryValues;
    
    ITUSAT_RTC rtc;
    ITUSAT_EEPROM eeprom;
    ITUSAT_CAMERA camera;
    ITUSAT_NTC thermistor1,thermistor2;
    ITUSAT_LIGHT light;
    ITUSAT_LM35 tempIN,tempOUT;
    ITUSAT_BATTERY battery;
    ITUSAT_XBEE xbee;
    ITUSAT_BUZZER buzzer;
    ITUSAT_SERVO  servo;
    Adafruit_BMP085 bmp_ada;
    ADXL345 adxl;
    BMP085 bmp;
    
    int             loopCounter;
    uint8_t         FSWstatus;
    uint8_t         missionStatusCheck ;
    uint8_t         eepromStatusCheck ;
    unsigned long   timeofStart ;
    unsigned long   timeNow ;
    float           baseAltitude;
    unsigned long   lastAddress;
    unsigned long   previousTime;
    
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
    void            seperateContainer();
    void            clearSensorvalues();
    float           calibrateAltitude();
    void            readSettings();
    void            calibrateSensorValues();
    

};







#endif /* defined(__ITUSAT_ENERGIA__ITUSAT_CORE__) */

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
#include "ITUSAT_BUZZER.h"
#include "ITUSAT_SERVO.h"
#include "TinyGPS.h"


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
#define PIN_CAMERA_OPEN         P2_6
#define PIN_CAMERA_CONTROL      P2_7
#define PIN_CAMERA_LED          P1_5



//// FSW DECIDERS
//#define FSW_SEPERATION_METERS       500
//#define FSW_SEPERATION_METERS_MAX   FSW_SEPERATION_METERS + 5
//#define FSW_SEPERATION_METERS_MIN   FSW_SEPERATION_METERS - 10
//#define FSW_LIGHT_THRESHOLD         100
//#define FSW_LAND_DECIDE_SECS        10
//#define FSW_LAND_DECIDE_METERS      10
//#define FSW_PREFLIGHT_ALTITUDE      3
//#define FSW_LAUNCHWAIT_ALTITUDE     7
//#define FSW_MIN_DEPLOYMENT_ALT      5

// FSW DECIDERS
#define FSW_SEPERATION_METERS       500
#define FSW_SEPERATION_METERS_MAX   FSW_SEPERATION_METERS + 5
#define FSW_SEPERATION_METERS_MIN   FSW_SEPERATION_METERS - 10
#define FSW_LIGHT_THRESHOLD         2500
#define FSW_LAND_DECIDE_SECS        10
#define FSW_LAND_DECIDE_METERS      10
#define FSW_LAUNCHWAIT_ALTITUDE     5
#define FSW_MIN_DEPLOYMENT_ALT      500




class ITUSAT_CORE
{
public:
    

    // helper variables
    int             loopCounter;
    uint8_t         FSWstatus;
    uint8_t         previousFSWStatus;
    uint8_t         missionStatusCheck ;
    uint8_t         eepromStatusCheck ;
    unsigned long   timeofStart ;
    unsigned long   timeNow ;
    float           baseAltitude;
    unsigned long   lastAddress;
    unsigned long   previousTime;
    unsigned int    lightValue;
    bool            newData;
    unsigned long   age;
    unsigned long   missionTime;
    
    
    
    // setup
    void            beginLEDS();
    void            beginModules();
    void            beginSerials();
    void            prepareMission(uint8_t);
    float           calibrateAltitude();
    void            warnReady();
    void            clearSensorvalues();
    void            calibrateSensorValues();
    void            toggle(uint8_t,int);
    

    // RTC wrapper functions
    unsigned long   rtc_millis();
    void            rtc_set_time(const char *year ,const char *month ,const char *day ,
                                 const char *hours, const char *mins,const char *secs);
    void            rtc_print_time();
    void            rtc_set_calibration();
    

    //telemetry

    void            sendTelemetry();
    void            saveTelemetry();
    void            readGPS();
    uint8_t         calculateCRC();
    
    // FSW
//    bool            controlPreFlightTest(float,unsigned int,int);
    uint8_t         decideLaunchWait(float,unsigned int,uint8_t);
    uint8_t         decideAscent(float,unsigned int,uint8_t);
    uint8_t         decideRocketDeployment(float,unsigned int,uint8_t);
    uint8_t         decideStabilization(float,unsigned int,uint8_t);
    uint8_t         decideSeparation(float,unsigned int,uint8_t);
    uint8_t         decideDescent(float,unsigned int,uint8_t);
    uint8_t         decideLanded(float,unsigned int,uint8_t);
    uint8_t         decideFSW();
    void            seperateContainer();
    void            land();
    
    //others
    void            readSettings();
    
    // Telemetry structure
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
        float           GPSlat;
        float           GPSlongt;
        float           GPSaltitude;
        char            stopByte;
        
    } telemetryValues;
    
    // Modules
    
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
    TinyGPS gps;
    ADXL345 adxl;
    BMP085 bmp;
    

};







#endif /* defined(__ITUSAT_ENERGIA__ITUSAT_CORE__) */

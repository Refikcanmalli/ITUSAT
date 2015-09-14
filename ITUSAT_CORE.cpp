//
//  ITUSAT_CORE.cpp
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 10/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#include "ITUSAT_CORE.h"

// Setup


void ITUSAT_CORE::beginLEDS()
{
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    pinMode(PIN_LED3, OUTPUT);
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
    
}

void ITUSAT_CORE::beginSerials()
{
    Serial.begin(9600);
}
void ITUSAT_CORE::beginModules()
{
    camera.prepare(PIN_CAMERA_OPEN, PIN_CAMERA_CONTROL, PIN_CAMERA_LED);
    eeprom.begin();
    missionStatusCheck = eeprom.readMissionState();
    buzzer.begin(PIN_BUZZER);
    tempIN.begin(PIN_LM35_IN);
    tempOUT.begin(PIN_LM35_OUT);
    battery.begin(PIN_BATTERY);
    light.begin(PIN_LIGHT);
    bmp_ada.begin();
    adxl.initialize();
    camera.prepare(PIN_CAMERA_OPEN, PIN_CAMERA_CONTROL, PIN_CAMERA_LED);
    servo.begin(PIN_SERVO);
    xbee.begin();
    rtc.begin();

}

void ITUSAT_CORE::prepareMission(uint8_t mod)
{
    if (mod  == 0) { // RTC
        // bu satir test icin
       // missionStatusCheck = MISSION_READY;
        // Mission daha once baslamis mi kontrolu
        if (missionStatusCheck == MISSION_READY) {
            // FSW sifirla ilk baslangic saatini kaydet
            rtc_set_time("2015","06","12","15","30","12");
            eeprom.writeData(MEM_FSW_ROCKET_DEPLOY,0);
            eeprom.writeData(MEM_FSW_SEPERATION, 0 );
            eeprom.writeData(MEM_FSW_LAND_COUNTER, 0);
            eeprom.writeAnything(MEM_MISSION_TIME, (unsigned long) 0 );
            FSWstatus = 0;
            eeprom.writePreviousFswState(FSWstatus);
            eeprom.writeCurrentFswState(0);
            eeprom.writeMissionState(MISSION_STARTED);
            baseAltitude = calibrateAltitude();
            // base altitude save
            eeprom.writeAnything(MEM_BASE_ALTITUDE, float(baseAltitude));
            // baslangic adresi
            eeprom.writeAnything(MEM_LAST_ADDRESS, MEM_TELEMETRY_START);
            clearSensorvalues();
            warnReady();
            rtc.get();
            timeofStart = rtc.time.hour*3600 + rtc.time.min*60 +  rtc.time.sec;
            eeprom.writeHours(rtc.time.hour);
            eeprom.writeMinutes(rtc.time.min);
            eeprom.writeSeconds(rtc.time.sec);
            
        }
        else if (missionStatusCheck == MISSION_STARTED)
        {
            // Power gitmis
            eeprom.writeData(MEM_POWER_STATUS, 0);
            eeprom.readAnything(MEM_BASE_ALTITUDE, baseAltitude);
            eeprom.readAnything(MEM_MISSION_TIME, missionTime);
            timeofStart = eeprom.readHours()*3600 + eeprom.readMinutes()*60 +  eeprom.readSeconds();
            FSWstatus = eeprom.readPreviousFswState();
            clearSensorvalues();
        }
        
    }
    else  // witout rtc
    {
        
        // bu satir test icin
        //missionStatusCheck = MISSION_READY;
        // Mission daha once baslamis mi kontrolu
        if (missionStatusCheck == MISSION_READY) {
            eeprom.writeData(MEM_FSW_ROCKET_DEPLOY,0);
            eeprom.writeData(MEM_FSW_SEPERATION, 0 );
            eeprom.writeData(MEM_CAMERA_STATUS, 0);
            FSWstatus = 0;
            eeprom.writePreviousFswState(FSWstatus);
            eeprom.writeCurrentFswState(0);
            eeprom.writeMissionState(MISSION_STARTED);
            baseAltitude = calibrateAltitude();
            eeprom.writeAnything(MEM_CAMERA_OPEN_SECS, (unsigned long) 0);
            eeprom.writeAnything(MEM_BASE_ALTITUDE, float(baseAltitude));
            eeprom.writeAnything(MEM_LAST_ADDRESS, MEM_TELEMETRY_START);
            eeprom.writeAnything(MEM_MISSION_TIME, (unsigned long)0);
            clearSensorvalues();
            warnReady();
            timeofStart = millis()/1000;
            
        }
        else if (missionStatusCheck == MISSION_STARTED)
        {
            // Power gitmis
            eeprom.readAnything(MEM_BASE_ALTITUDE, baseAltitude);
            timeofStart = eeprom.readHours()*3600 + eeprom.readMinutes()*60 +  eeprom.readSeconds();
            FSWstatus = eeprom.readPreviousFswState();
            clearSensorvalues();
            eeprom.readAnything(MEM_MISSION_TIME, (missionTime));
        }
    
    }
 
   
    
    
}


void ITUSAT_CORE::warnReady()
{
    
    digitalWrite(PIN_LED1, HIGH);
    delay(100);
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, HIGH);
    delay(100);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, HIGH);
    delay(100);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_BUZZER, HIGH);
    delay(100);
    digitalWrite(PIN_BUZZER, LOW);
    delay(700);
    digitalWrite(PIN_LED1, HIGH);
    delay(100);
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, HIGH);
    delay(100);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, HIGH);
    delay(100);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_BUZZER, HIGH);
    delay(100);
    digitalWrite(PIN_BUZZER, LOW);
    delay(700);
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
    digitalWrite(PIN_LED3, HIGH);
    digitalWrite(PIN_BUZZER, HIGH);
    delay(100);
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_BUZZER, LOW);
    delay(100);
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
    digitalWrite(PIN_LED3, HIGH);
    digitalWrite(PIN_BUZZER, HIGH);
    delay(100);
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_BUZZER, LOW);
    delay(100);
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
    digitalWrite(PIN_LED3, HIGH);
    digitalWrite(PIN_BUZZER, HIGH);
    delay(100);
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_BUZZER, LOW);
    delay(100);
    
    
    
    
}

void ITUSAT_CORE::clearSensorvalues()
{
    telemetryValues.startByte               = '(' ;
    telemetryValues.insideTemperature       = 0.0 ;
    telemetryValues.outsideTemperature      = 0.0 ;
    telemetryValues.altitude                = 0.0 ;
    telemetryValues.accX                    = 0.0 ;
    telemetryValues.accY                    = 0.0 ;
    telemetryValues.accZ                    = 0.0 ;
    telemetryValues.batteryVoltage          = 0.0 ;
    telemetryValues.stopByte                = ')' ;
    
    lightValue                              = 0;
    
}


float ITUSAT_CORE::calibrateAltitude()
{
    float alt = 0.0;
    for (int i = 0 ; i<10; i++) {
        alt += bmp_ada.readAltitude();
    }
    
    return alt/10;
}

void ITUSAT_CORE::calibrateSensorValues()
{
    
    telemetryValues.altitude = telemetryValues.altitude/loopCounter -baseAltitude;
    telemetryValues.outsideTemperature /= loopCounter;
    telemetryValues.insideTemperature/=loopCounter;
    telemetryValues.batteryVoltage/=loopCounter;
    telemetryValues.accX/=loopCounter;
    telemetryValues.accY/=loopCounter;
    telemetryValues.accZ/=loopCounter;
    
    
    telemetryValues.insideTemperature -= 5;
    telemetryValues.batteryVoltage += 0.2; 
    lightValue /=loopCounter;
}

void ITUSAT_CORE::toggle(uint8_t pin , int mil)
{
    digitalWrite(pin, HIGH);
    delay(mil);
    digitalWrite(pin, LOW);
    delay(mil);
    digitalWrite(pin, HIGH);
    delay(mil);
    digitalWrite(pin, LOW);
}


// RTC functions

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

void ITUSAT_CORE::rtc_print_time()
{
    char dateString[35];
    
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

void ITUSAT_CORE::rtc_set_time(const char *year ,const char *month ,const char *day ,const char *hours, const char *mins,const char *secs)
{
    
    uint8_t x, y, u8Status;
    ITUSAT_RTC::time_t newtime;
    
    
    x = Serial.read(); // discard digit
    x = Serial.read(); // discard digit
    x = Serial.read(); // year: tens digit
    y = Serial.read(); // year: ones digit
    newtime.year = 10 * (year[2] - '0') + (year[3] - '0');
    
    x = Serial.read(); // discard spacer
    x = Serial.read(); // month: tens digit
    y = Serial.read(); // month: ones digit
    newtime.month = 10 * (month[0] - '0') + (month[1] - '0');
    
    x = Serial.read(); // discard spacer
    x = Serial.read(); // day: tens digit
    y = Serial.read(); // day: ones digit
    newtime.day = 10 * (day[0] - '0') + (day[1] - '0');
    
    x = Serial.read(); // discard spacer
    x = Serial.read(); // hour: tens digit
    y = Serial.read(); // hour: ones digit
    newtime.hour = 10 * (hours[0] - '0') + (hours[1] - '0');
    
    x = Serial.read(); // discard spacer
    x = Serial.read(); // min: tens digit
    y = Serial.read(); // min: ones digit
    newtime.min = 10 * (mins[0] - '0') + (mins[1] - '0');
    
    x = Serial.read(); // discard spacer
    x = Serial.read(); // sec: tens digit
    y = Serial.read(); // sec: ones digit
    newtime.sec = 10 * (secs[0]- '0') + (secs[1] - '0');
    newtime.dow = 1;
    
    u8Status = rtc.set(&newtime);
    if (u8Status)
    {
        Serial.print("Unable to set time due to I2C error 0x");
        Serial.print(u8Status, HEX);
        Serial.println(".");
    }
    rtc_print_time();
    
    
}


// telemetry

void ITUSAT_CORE::sendTelemetry()
{
    uint8_t randCRC = random(0, 255);
    xbee.addEnvelope(0);
    xbee.addData(TEAM_NUMBER);
    xbee.addData(timeNow);
    xbee.addData(telemetryValues.altitude);
    xbee.addData(telemetryValues.outsideTemperature);
    xbee.addData(telemetryValues.insideTemperature);
    xbee.addData(telemetryValues.batteryVoltage);
    xbee.addData(FSWstatus);
    xbee.addData(telemetryValues.accX);
    xbee.addData(telemetryValues.accY);
    xbee.addData(telemetryValues.accZ);
    xbee.addGPSData(-99.273810);
    xbee.addGPSData(31.970003);
    xbee.addData(460.6);
//    xbee.addGPSData(telemetryValues.GPSlat);
//    xbee.addGPSData(telemetryValues.GPSlongt);
//    xbee.addData(telemetryValues.GPSaltitude);
    xbee.addCRC(randCRC); //crc
    xbee.addEnvelope(1);
    
}

void ITUSAT_CORE::saveTelemetry()
{
    // read current fsw - read previos fsw
    uint8_t preEEPROM = eeprom.readPreviousFswState();
    uint8_t curEEPROM = eeprom.readCurrentFswState();
    if ((curEEPROM - preEEPROM ) >1) {
        Serial.print("cur: ");
        Serial.println(curEEPROM );
        Serial.print("pre: ");
        Serial.println(preEEPROM );
        Serial.println("");
        FSWstatus = preEEPROM +1 ;
        toggle(P1_3, 10);
    }
    else
    {
        FSWstatus = curEEPROM;
    }
    telemetryValues.time = timeNow;
    telemetryValues.FSWstatus = FSWstatus;
    eeprom.readAnything(MEM_LAST_ADDRESS, lastAddress);
    eeprom.writePreviousFswState(FSWstatus);
    eeprom.writeAnything(lastAddress, telemetryValues);
    eeprom.writeAnything(MEM_LAST_ADDRESS, lastAddress+sizeof(telemetryValues));
}

void ITUSAT_CORE::readGPS()
{
  
//        Serial1.print("LAT=");
//        Serial1.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
//        Serial1.print(" LON=");
//        Serial1.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
//        Serial1.print(" SAT=");
//        Serial1.print(gps.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gps.satellites());
//        Serial1.print(" PREC=");
//        Serial1.print(gps.hdop() == TinyGPS::GPS_INVALID_HDOP ? 0 : gps.hdop());


}




// FSW

uint8_t ITUSAT_CORE::decideFSW()
{
    uint8_t preFSW = eeprom.readPreviousFswState();
    uint8_t curFSW = eeprom.readCurrentFswState();
    uint8_t newFSW =0;
    float altitude = telemetryValues.altitude/loopCounter - baseAltitude;
    unsigned int curLight = lightValue/loopCounter;
    
//    Serial.print(altitude);
//    Serial.print("-");
  Serial.print(curLight);
    Serial.print("-");
    Serial.print(curFSW);
    Serial.print(" ");
    
    switch (curFSW) {
        case 0:
            newFSW =  decideLaunchWait(altitude, curLight, curFSW);
            break;
        case 1:
            newFSW =  decideAscent(altitude, curLight,  curFSW);
            break;
        case 2:
            newFSW =  decideRocketDeployment(altitude, curLight,  curFSW);
            break;
        case 3:
            newFSW =  decideStabilization(altitude, curLight,  curFSW);
            break;
        case 4:
            newFSW =  decideSeparation(altitude, curLight,  curFSW);
            break;
        case 5:
            newFSW =  decideDescent(altitude, curLight,  curFSW);
            break;
        case 6:
            newFSW =  decideLanded(altitude, curLight,  curFSW);
            break;
        case 7:
            newFSW =  curFSW;
            digitalWrite(PIN_BUZZER, HIGH);
            eeprom.writeData(MEM_EEPROM_STATE  , EEPROM_STATE_LOCK);
            if (eeprom.readData(MEM_CAMERA_STATUS) == 1) {
                camera.stopRecord(500);
                camera.close(1000);
                eeprom.writeData(MEM_CAMERA_STATUS, 2);
            }
            
            break;
            
        default:
            newFSW =  curFSW;
            
            break;
    }
    
    return newFSW;
    
    }

uint8_t ITUSAT_CORE::decideLaunchWait(float altitude, unsigned int light, uint8_t currentFSW)
{
    if (light<FSW_LIGHT_THRESHOLD  && altitude < FSW_LAUNCHWAIT_ALTITUDE) {
        if (eeprom.readData(MEM_CAMERA_STATUS) == 0) {
            camera.open(2000);
            camera.startRecord(1000);
            eeprom.writeData(MEM_CAMERA_STATUS , 1);
        }
        return 1;
    }
    else
        return currentFSW;
}


uint8_t ITUSAT_CORE::decideAscent(float altitude, unsigned int light, uint8_t currentFSW)
{
    if (light<FSW_LIGHT_THRESHOLD  && altitude > FSW_LAUNCHWAIT_ALTITUDE) {

        
        return 2;
    }
    else
         return currentFSW;
}

uint8_t ITUSAT_CORE::decideRocketDeployment(float altitude, unsigned int light, uint8_t currentFSW)
{
    if (light > FSW_LIGHT_THRESHOLD  && altitude > FSW_LAUNCHWAIT_ALTITUDE) {
        eeprom.writeData(MEM_FSW_ROCKET_DEPLOY, 1);
      //  saveRocketDeploymentTelemetry();
        return 3;
    }
    else
         return currentFSW;
}

uint8_t ITUSAT_CORE::decideStabilization(float altitude, unsigned int light, uint8_t currentFSW)
{
    if (eeprom.readData(MEM_FSW_ROCKET_DEPLOY) == 1) {
        
        return 4;
    }
    else
         return currentFSW;
}

uint8_t ITUSAT_CORE::decideSeparation(float altitude, unsigned int light, uint8_t currentFSW)
{
    if (altitude <FSW_SEPERATION_METERS_MAX) {
        servo.myservo.attach(PIN_SERVO);
        servo.turn(0);
        eeprom.writeData(MEM_FSW_SEPERATION, 1);
        return 5;
    }
    else
         return currentFSW;
}

uint8_t ITUSAT_CORE::decideDescent(float altitude, unsigned int light, uint8_t currentFSW)
{
    if (eeprom.readData(MEM_FSW_SEPERATION) == 1) {
        
        return 6;
    }
    else
         return currentFSW;
}

uint8_t ITUSAT_CORE::decideLanded(float altitude, unsigned int light, uint8_t currentFSW)
{
    uint8_t landedcounter = eeprom.readData(MEM_FSW_LAND_COUNTER);
    if (altitude < FSW_LAND_DECIDE_METERS)
        eeprom.writeData(MEM_FSW_LAND_COUNTER, landedcounter++);
    if (landedcounter > 5) {
        return 7;
    }
    else
         return currentFSW;
}




// others

void ITUSAT_CORE::readSettings()
{
    Serial.println("*********************");
    Serial.print("Eeprom State : ");
    if (eeprom.readData(MEM_EEPROM_STATE) == EEPROM_STATE_LOCK)
    {
        Serial.println("LOCKED");
    }
    else
        Serial.println("UNLOCKED");
    Serial.print("Mission State : ");
    if (eeprom.readData(MEM_MISSION_STATE) == MISSION_STARTED)
    {
        Serial.println("STARTED");
    }
    else
    Serial.println("STOPPED");
    
    
    Serial.print("Flight Software State : ");
    Serial.println(eeprom.readData(MEM_PREVIOUS_FSW));
    Serial.print("Last Written Address : ");
    eeprom.readAnything(MEM_LAST_ADDRESS, lastAddress);
    Serial.println(lastAddress);
    Serial.print("HOUR : ");
    Serial.println(eeprom.readHours());
    Serial.print("MINUTES : ");
    Serial.println(eeprom.readMinutes());
    Serial.print("SECONDS : ");
    Serial.println(eeprom.readSeconds());
    Serial.print("MISSION TIME : ");
    eeprom.readAnything(MEM_MISSION_TIME, timeNow);
    Serial.println(timeNow);
    Serial.println("*********************");

}











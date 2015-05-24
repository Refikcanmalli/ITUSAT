#include <ITUSAT_CORE.h>


// string to store current time/date
char dateString[50];
ITUSAT_CORE Core;



void setup()
{
    // initialize serial interface
    Serial.begin(9600);
    
    // initialize i2c interface
    Core.rtc.begin();
}


void loop()
{
    uint8_t k, u8Status;
    
    if (Core.rtc.isStopped())
    {
        Serial.println("RTC is stopped.");
        Serial.print("Recent: ");
    }
    else
    {
        if (Core.rtc.isFailed())
        {
            Serial.println("RTC is running (fail bit is set).");
        }
        else
        {
            Serial.println("RTC is running.");
        }
        Serial.print("Currently: ");
    }
    
    Core.rtc_print_time(dateString);
    Serial.println("");
    Serial.println("S - [S]tart RTC");
    Serial.println("P - sto[P] RTC");
    Serial.println("F - clear [F]ault");
    Serial.println("T - set [T]ime");
    Serial.println("C - set [C]al");
    Serial.println("D - [D]isplay current time");
    Serial.println("");
    Serial.println("Choose a menu item:");
    
    while (!Serial.available())
    {
    }
    
    Serial.println("----------------------------------------");
    
    k = Serial.read();
    switch(k)
    {
        case 'S':
        case 's':
            u8Status = Core.rtc.start();
            if (u8Status)
            {
                Serial.print("Unable to start RTC due to I2C error 0x");
                Serial.print(u8Status, HEX);
                Serial.println(".");
            }
            break;
            
        case 'P':
        case 'p':
            u8Status = Core.rtc.stop();
            if (u8Status)
            {
                Serial.print("Unable to stop RTC due to I2C error 0x");
                Serial.print(u8Status, HEX);
                Serial.println(".");
            }
            break;
            
        case 'F':
        case 'f':
            u8Status = Core.rtc.clearFault();
            if (u8Status)
            {
                Serial.print("Unable to clear RTC fault due to I2C error 0x");
                Serial.print(u8Status, HEX);
                Serial.println(".");
            }
            break;
            
        case 'T':
        case 't':
            Core.rtc_set_time();
            break;
            
        case 'C':
        case 'c':
            Core.rtc_set_calibration();
            break;
            
        case 'D':
        case 'd':
        default:
            break;
    }
    
    Serial.flush();
}





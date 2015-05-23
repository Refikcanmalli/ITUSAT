///
/// @mainpage	I2C_Scanner
///
/// @details	CANSAT
/// @n
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Refikcan Malli
/// @author		Refikcan Malli
/// @date		23/05/15 18:18
/// @version	<#version#>
///
/// @copyright	(c) Refikcan Malli, 2015
/// @copyright	GNU General Public Licence
///
/// @see		ReadMe.txt for references
///


///
/// @file		I2C_Scanner.ino
/// @brief		Main sketch
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Refikcan Malli
/// @author		Refikcan Malli
/// @date		23/05/15 18:18
/// @version	<#version#>
///
/// @copyright	(c) Refikcan Malli, 2015
/// @copyright	GNU General Public Licence
///
/// @see		ReadMe.txt for references
/// @n
///
#include "Energia.h"

#include <Wire.h>


void setup()
{
    Wire.begin();
    
    Serial.begin(9600);
    Serial.println("\nI2C Scanner");
}


void loop()
{
    byte error, address;
    int nDevices;
    
    Serial.println("Scanning...");
    
    nDevices = 0;
    for(address = 1; address < 127; address++ )
    {
        // The i2c_scanner uses the return value of
        // the Write.endTransmisstion to see if
        // a device did acknowledge to the address.
        Wire.beginTransmission(address);
        Wire.write(1);
        error = Wire.endTransmission();
        
        if (error == 0)
        {
            Serial.print("I2C device found at address 0x");
            if (address<16)
                Serial.print("0");
            Serial.print(address,HEX);
            Serial.println("  !");
            
            nDevices++;
        }
        else if (error==4)
        {
            Serial.print("Unknow error at address 0x");
            if (address<16)
                Serial.print("0");
            Serial.println(address,HEX);
        }
    }
    if (nDevices == 0)
        Serial.println("No I2C devices found\n");
    else
        Serial.println("done\n");
    
    delay(50);           // wait 5 seconds for next scan
}


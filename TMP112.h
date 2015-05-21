#ifndef TMP112_H
#define TMP112_H

#if (ARDUINO >= 100)
#include "Arduino.h"
#endif
#include "Wire.h"

#define TMP112_ADDRESS1                  (0x48)
#define TMP112_ADDRESS2                  (0x50)

class TMP112
{
    
public:
    TMP112();
   
    byte firstbyte, secondbyte;
    int val;
    float convertedtemp;
    float correctedtemp;
    uint8_t choosenAddress;

    void begin(uint8_t);
    float readTemperature();
    
};



#endif


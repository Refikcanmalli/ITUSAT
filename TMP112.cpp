

#include "TMP112.h"


TMP112::TMP112()
{
    
}

void TMP112::begin(uint8_t adress)
{
    
}

float TMP112::readTemperature()
{
    
    Wire.beginTransmission(choosenAddress); //Say hi to the sensor.
    Wire.write(0x00);
    Wire.endTransmission();
    Wire.requestFrom(choosenAddress, 2);
    Wire.endTransmission();

    firstbyte      = (Wire.read());
    /*read the TMP102 datasheet - here we read one byte from
    each of the temperature registers on the TMP102*/
    secondbyte     = (Wire.read());
    /*The first byte contains the most significant bits, and
    the second the less significant */
    val = ((firstbyte) << 4);
    /* MSB */
    val |= (secondbyte >> 4);
    /* LSB is ORed into the second 4 bits of our byte.
    Bitwise maths is a bit funky, but there's a good tutorial on the playground*/
    convertedtemp = val*0.0625;
    correctedtemp = convertedtemp - 5;
    /* See the above note on overreading */
    
    return correctedtemp;
}
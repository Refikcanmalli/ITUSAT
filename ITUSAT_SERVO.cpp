//
//  ITUSAT_SERVO.cpp
//  ITUSAT_DEV
//
//  Created by Refikcan Malli on 05/06/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#include "ITUSAT_SERVO.h"



ITUSAT_SERVO::ITUSAT_SERVO()
{
    
}

void ITUSAT_SERVO::begin(uint8_t pin)
{
    
    myservo.attach(pin);
    digitalWrite(pin, LOW);
    
}


void ITUSAT_SERVO::turn(uint8_t side)
{
    
    if (side == 0)
    {
        for(pos = SERVO_MINDEGREE; pos < SERVO_MAXDEGREE; pos += 1)  // goes from 0 degrees to 180 degrees
        {                                  // in steps of 1 degree
            myservo.write(pos);
            delay(SERVO_DELAY);
        }
        
    }
    
    else
    {
    
        for(pos = SERVO_MAXDEGREE; pos < SERVO_MINDEGREE; pos += 1)
        {
            myservo.write(pos);
            delay(SERVO_DELAY);
            
        }
    }

}



//
//  ITUSAT_SERVO.h
//  ITUSAT_DEV
//
//  Created by Refikcan Malli on 05/06/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#ifndef __ITUSAT_DEV__ITUSAT_SERVO__
#define __ITUSAT_DEV__ITUSAT_SERVO__


#include "Energia.h"
#include <Servo.h>

#define SERVO_DEGREE        90
#define SERVO_DELAY         10
#define SERVO_MINDEGREE     80
#define SERVO_MAXDEGREE     170




class ITUSAT_SERVO {
    
public:
    
    ITUSAT_SERVO();
    Servo   myservo;
    int     pos;
    uint8_t selectedPin;
    void    begin(uint8_t);
    void    turn(uint8_t);
    
};


#endif /* defined(__ITUSAT_DEV__ITUSAT_SERVO__) */

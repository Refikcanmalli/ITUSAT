//
//  ITUSAT_BUZZER.cpp
//  ITUSAT_DEV
//
//  Created by Refikcan Malli on 27/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#include "ITUSAT_BUZZER.h"

#define NOTE_C4_1 260


// notes in the melody:
int melody[] = {
    NOTE_C4_1,NOTE_C4, NOTE_D4, NOTE_C4,NOTE_F4,NOTE_E4,
    NOTE_C4_1,NOTE_C4,NOTE_D4,NOTE_C4,NOTE_G4,NOTE_F4,
    NOTE_C4_1,NOTE_C4,NOTE_C5,NOTE_A4,NOTE_F4,NOTE_F4, NOTE_E4,NOTE_D4,
    NOTE_AS4,NOTE_AS4,NOTE_A4,NOTE_F4,NOTE_G4,NOTE_F4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
    4, 4, 2, 2,2,1,
    4, 4, 2, 2,2,1,
    4, 4, 2, 2,4,4,2,1,
    4, 4, 2, 2,2,1};

ITUSAT_BUZZER::ITUSAT_BUZZER()
{
    
}

void ITUSAT_BUZZER::begin(uint8_t pin)

{
    buzzerPin = pin;
    pinMode(pin, OUTPUT);
}

void ITUSAT_BUZZER::play()
{

    for (int thisNote = 0; thisNote < 26; thisNote++) {
        
        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000/noteDurations[thisNote];
        tone(buzzerPin, melody[thisNote],noteDuration);
        
        int pauseBetweenNotes = noteDuration + 50;      //delay between pulse
        delay(pauseBetweenNotes);
        
        noTone(buzzerPin);                // stop the tone playing
    }

}

void ITUSAT_BUZZER::playImperial()
{

    beep(a, 500);
    beep(a, 500);
    beep(a, 500);
    beep(ff, 350);
    beep(cH, 150);
    beep(a, 500);
    beep(ff, 350);
    beep(cH, 150);
    beep(a, 650);
    
    delay(150);
    //end of first bit
    
    beep(eH, 500);
    beep(eH, 500);
    beep(eH, 500);
    beep(fH, 350);
    beep(cH, 150);
    beep(gS, 500);
    beep(ff, 350);
    beep(cH, 150);
    beep(a, 650);
    
    delay(150);
    //end of second bit...
    
    beep(aH, 500);
    beep(a, 300);
    beep(a, 150);
    beep(aH, 400);
    beep(gSH, 200);
    beep(gH, 200);
    beep(fSH, 125);
    beep(fH, 125);
    beep(fSH, 250);
    
    delay(250);
    
    beep(aS, 250);
    beep(dSH, 400);
    beep(dH, 200);
    beep(cSH, 200);
    beep(cH, 125);
    beep(b, 125);
    beep(cH, 250);
    
    delay(250);
    
    beep(ff, 125);
    beep(gS, 500);
    beep(ff, 375);
    beep(a, 125);
    beep(cH, 500);
    beep(a, 375);
    beep(cH, 125);
    beep(eH, 650);
    
    
    beep(aH, 500);
    beep(a, 300);
    beep(a, 150);
    beep(aH, 400);
    beep(gSH, 200);
    beep(gH, 200);
    beep(fSH, 125);
    beep(fH, 125);
    beep(fSH, 250);
    
    delay(250);
    
    beep(aS, 250);
    beep(dSH, 400);
    beep(dH, 200);
    beep(cSH, 200);
    beep(cH, 125);  
    beep(b, 125);  
    beep(cH, 250);      
    
    delay(250);
    
    beep(ff, 250);  
    beep(gS, 500);  
    beep(ff, 375);  
    beep(cH, 125);
    beep(a, 500);   
    beep(ff, 375);   
    beep(cH, 125); 
    beep(a, 650);   
    //end of the song
    //end of the song
    

}

void ITUSAT_BUZZER::beep(int note, int duration)
{
    tone(buzzerPin, note, duration/2);
    delay(duration/2);
    noTone(buzzerPin);
    delay(duration/2 + 20);
}



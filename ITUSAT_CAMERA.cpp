

#include "ITUSAT_CAMERA.h"
#include "Energia.h"


ITUSAT_CAMERA::ITUSAT_CAMERA(){


}


void ITUSAT_CAMERA::prepare(int p_open,int p_cont,int p_sta){
    
    P_openclose = p_open;
    P_control   = p_cont;
    P_status    = p_sta;
    pinMode(P_openclose ,OUTPUT);
    pinMode(P_control   ,OUTPUT);
    pinMode(P_status   ,OUTPUT);
    digitalWrite(P_openclose,   HIGH);
    digitalWrite(P_control,     LOW);
    digitalWrite(P_status,      LOW);
    isOpen =      false;
    isRecording =   false;
}
void ITUSAT_CAMERA::open(int time){
    
    digitalWrite(P_openclose,   LOW);
    delay(time);
    digitalWrite(P_openclose,   HIGH);
    isOpen = true;
    delay(1000);
    
    

}
void ITUSAT_CAMERA::close(int time)
{

    digitalWrite(P_openclose,   LOW);
    delay(time);
    digitalWrite(P_openclose,   HIGH);
    isOpen = false;

}
void ITUSAT_CAMERA::startRecord(int time){
    
    digitalWrite(P_control,     HIGH);
    delay(time);
    digitalWrite(P_control,     LOW);
    delay(50);
    digitalWrite(P_status,      HIGH);
    isRecording = true;
}
void ITUSAT_CAMERA::stopRecord(int time){
    
    
    digitalWrite(P_control,     HIGH);
    delay(time);
    digitalWrite(P_control,     LOW);
    delay(50);
    digitalWrite(P_status,      LOW);
    delay(500);
    
    isRecording = false;

    
}
void ITUSAT_CAMERA::takePhoto(){

}
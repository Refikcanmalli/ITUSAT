/*
 * ITUSAT_Camera.h
 *
 *  Created on: Dec 16, 2014
 *      Author: Refikcanmalli
 *  ITUSAT_CAMERA V 1.0
 */

#ifndef ITUSAT_CAMERA_H_
#define ITUSAT_CAMERA_H_


#include "Energia.h"



class ITUSAT_CAMERA {
 public:
    int P_openclose,P_control,P_status;
    boolean isOpen,isRecording;
    ITUSAT_CAMERA();
    
    
    void prepare(int p_open,int p_cont,int p_sta);
    void open(int time);
    void close(int time);
    void startRecord(int time);
    void stopRecord(int time);
    void takePhoto();


};



#endif /* ITUSAT_CAMERA_H_ */

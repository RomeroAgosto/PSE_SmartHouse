#ifndef STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H
#define STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H

#include "statemachines.h"

#define GREEN 0
#define YELLOW 1
#define RED 2


#define TRUE 1
#define FALSE 0


int SetAirThreshold(int room,int warning_level, int threshold, double value);
int GetAirQualityState(void);
int SetVentilationState_dummy(int room,int on);
int SetLightQuality_dummy( int room, int light);
void Statemachine_AirQuality(int room);
int SetWarning(void);

#endif //STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H

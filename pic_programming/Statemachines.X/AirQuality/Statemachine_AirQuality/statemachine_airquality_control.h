#ifndef STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H
#define STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H

#include "../../statemachines.h"

#define GREEN 0
#define YELLOW 1
#define RED 2


#define TRUE 1
#define FALSE 0


int SetAirThreshold(int room,int warning_level,int threshold_for_sensor, double value);
int GetAirQualityState(int room);
int SetHysteresis(int stage, int sensor, double value);
int SetWarning(void);

#if UNITTEST == 1
void Statemachine_AirQuality(int room,int *test);
void SetAirQuality(int room, double *input_values);
void GetAirQuality(int room, double *sensor_values);
void SetLightQuality(int room, int color);
void SetVentilationState(int room, int on);
void ResetAirQualityState();
#else
void Statemachine_AirQuality(int room);
#endif

#endif //STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H

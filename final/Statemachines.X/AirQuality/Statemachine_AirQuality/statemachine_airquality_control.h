#ifndef STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H
#define STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H

#include "../../statemachines.h"

#define GREEN 0
#define YELLOW 1
#define RED 2




int GetAirQualityState(int room);
int SetHysteresis(int stage, int sensor, int value);
int SetWarning(void);

#if UNITTEST == 1
void Statemachine_AirQuality(int room,int *test);
void setVentilatorBuzzer( int color);
//void GetAirQuality(int room, int *sensor_values);
void SetAirQuality(int room, int *input_values);
void SetLightQuality(int room, int color);
//void SetVentilatorState(int room,int on);
void ResetAirQualityState();
int set_air_quality_hysteresis(int risk_level,int sensor, int value);
int get_air_quality_hysteresis(int risk_level,int sensor);
int set_air_quality_threshold(int room,int risk_level, int threshold, int value);
int get_air_quality_threshold(int room,int risk_level, int threshold);

#else
void Statemachine_AirQuality(int room);
#endif

#endif //STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H

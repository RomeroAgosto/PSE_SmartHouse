#ifndef STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H
#define STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H

#include "../../statemachines.h"

#define GREEN 0
#define YELLOW 1
#define RED 2




int get_air_quality_state(int room);

#if UNITTEST == 1
void statemachine_air_quality(int room,int *test);
void set_ventilator_buzzer( int color);
void get_air_quality(int room, int *sensor_values);
void set_air_quality(int room, int *input_values);
void set_light_quality(int room, int color);
void set_ventilator_state(int room,int on);
void reset_air_quality_state(void);
int set_air_quality_hysteresis(int risk_level,int sensor, int value);
int get_air_quality_hysteresis(int risk_level,int sensor);
int set_air_quality_threshold(int risk_level, int threshold, int value);
int get_air_quality_threshold(int risk_level, int threshold);

#else
void statemachine_air_quality(int room);
#endif

#endif //STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H

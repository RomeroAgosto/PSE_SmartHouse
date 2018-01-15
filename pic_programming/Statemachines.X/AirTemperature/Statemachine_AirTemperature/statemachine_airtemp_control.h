#ifndef STATEMACHINE_STATEMACHINE_AIRTEMP_CONTROL_H
#define STATEMACHINE_STATEMACHINE_AIRTEMP_CONTROL_H

#include "../../statemachines.h"

#define DESIRED_TEMPERATURE 0  /*!< Represents a state*/
#define INCREASE_AIR_TEMPERATURE 1 /*!< Represents a state*/


int set_threshold_air(int room, int threshold);

#if UNITTEST == 1
int desiredAirTemperature(int room);
int SetHeatingAirState(int room, int on);
int GetAirTemperature(int room);
void Statemachine_AirControl(int room, int *test);
int setdesiredTemp(int room,int temp);
int SetAirTemperature(int room, int temp);
void reset_state_air_temp(int room);
#else
void Statemachine_AirControl(int room);

#endif

#endif //STATEMACHINE_STATEMACHINE_AIRTEMP_CONTROL_H

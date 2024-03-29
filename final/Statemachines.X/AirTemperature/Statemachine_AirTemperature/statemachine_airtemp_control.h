#ifndef STATEMACHINE_STATEMACHINE_AIRTEMP_CONTROL_H
#define STATEMACHINE_STATEMACHINE_AIRTEMP_CONTROL_H

#include "../../statemachines.h"

#define DESIRED_TEMPERATURE 0  /*!< Represents a state*/
#define INCREASE_AIR_TEMPERATURE 1 /*!< Represents a state*/


#if UNITTEST == 1
int desired_air_temperature(int room);
int set_air_heater(int room, int on);
int get_air_temperature(int room);
void statemachine_air_control(int room, int *test);
int set_desired_temp(int room,int temp);
int set_air_temperature(int room, int temp);
void reset_state_air_temp(int room);
#else
void statemachine_air_control(int room);

#endif

#endif //STATEMACHINE_STATEMACHINE_AIRTEMP_CONTROL_H

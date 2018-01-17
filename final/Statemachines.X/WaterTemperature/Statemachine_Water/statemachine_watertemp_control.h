
#ifndef STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H
#define STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H

#include "../../statemachines.h"


#define DESIRED_TEMPERATURE 0
#define INCREASE_WATER_TEMPERATURE 1


static int water_temp_state=0;


#if UNITTEST==1
int set_water_hysteresis(int limit);
int get_water_hysteresis(void);
int get_water_temperature();
int set_water_temp(int temp);
int set_desired_temperature(int temp);
int desired_water_temperature();
int set_water_heater_state(int set);
int reset_state_water_temp();
int statemachine_water_control(int *test);
#else
void statemachine_water_control(void);
#endif



#endif //STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H

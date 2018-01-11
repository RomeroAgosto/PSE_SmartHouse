
#ifndef STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H
#define STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H

#include "../../statemachines.h"


#define DESIRED_TEMPERATURE 0
#define INCREASE_WATER_TEMPERATURE 1
#define FALSE 0
#define TRUE 1

static int water_temp_state=0;

static int upper_threshold_water=65; /*just to provide initial values*/
static int lower_threshold_water=55;

#if UNITTEST==1
int GetWaterTemperature();
int set_water_temp(int temp);
int set_desired_temperature(int temp);
int desiredWaterTemperature();
int SetWaterHeaterSate(int set);
int reset_state_water_temp();
int Statemachine_WaterControl(int *test);
#else
void Statemachine_WaterControl(void);
//int GetWaterTemperature(int Temp);
#endif



#endif //STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H

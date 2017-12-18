//
// Created by sascha on 02-12-2017.
//

#ifndef STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H
#define STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H

#include "statemachines.h"

#define DESIRED_TEMPERATURE 0
#define INCREASE_WATER_TEMPERATURE 1
#define FALSE 0
#define TRUE 1

static int water_temp_state=0;

static int upper_threshold_water=65; /*just to provide initial values*/
static int lower_threshold_water=55;


int GetWaterTemperature(void);
int SetWaterHeaterSate_dummy(int Command);
int desiredWaterTemperature_dummy(void);
void Statemachine_WaterControl(void);

#endif //STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H

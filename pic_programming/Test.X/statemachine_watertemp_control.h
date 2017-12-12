//
// Created by sascha on 02-12-2017.
//

#ifndef STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H
#define STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H


#include "stdio.h"
#include <stdlib.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include <string.h>


#define DESIRED_TEMPERATURE 0
#define INCREASE_WATER_TEMPERATURE 1
#define FALSE 0
#define TRUE 1

static int water_temp_state=0;

static int upper_threshold=65; /*just to provide initial values*/
static int lower_threshold=55;


int GetWaterTemperature(void);
int SetHeatingWater(int Command);
void Statemachine_WaterControl(int upper_threshold,char *to_send);

#endif //STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H

//
// Created by sascha on 03-12-2017.
//

#ifndef STATEMACHINE_STATEMACHINE_AIRTEMP_CONTROL_H
#define STATEMACHINE_STATEMACHINE_AIRTEMP_CONTROL_H

#include "statemachines.h"

#define DESIRED_TEMPERATURE 0
#define INCREASE_AIR_TEMPERATURE 1
#define DECREASE_AIR_TEMPERATURE 2
#define FALSE 0
#define TRUE 1

static int upper_threshold_air; /*e.g. when the desired temperature is 25*/
static int lower_threshold_air;

static int air_temp_state[4]={0};

void Statemachine_AirControl(int room);

#endif //STATEMACHINE_STATEMACHINE_AIRTEMP_CONTROL_H

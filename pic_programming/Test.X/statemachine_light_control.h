
/*
 * File:   statemachine.h
 * Author: sascha
 *
 * Created on November 28, 2017, 7:38 PM
 */

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "stdio.h"
#include <stdlib.h>


#define TURNED_OFF 0
#define TURNED_ON 1
#define TRUE 1
#define FALSE 0

#define CYCLES 3 /*after CYCLES the light is turned off again */

static int counter[4]={0}; /* Counter for all timer/lights */
static int light_state[4]={0};

int *update_sensorvalues(int *sensor_values);
void Statemachine_LightControl(int light,char* to_send);
int create_message(char *existing_string, char *new_input);
int SetTimer(int number);
int SetLight(int number, int on); /* parameters are the light number and if the light is supposed to be on (TRUE) or off (FALSE)*/


#endif /* STATEMACHINE_H */


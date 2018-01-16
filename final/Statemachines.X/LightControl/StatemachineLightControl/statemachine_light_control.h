
/*
 * File:   statemachine.h
 * Author: sascha
 *
 * Created on November 28, 2017, 7:38 PM
 */

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "../../statemachines.h"

#define TURNED_OFF 0
#define TURNED_ON 1




int set_timer(int light);
int get_cycle(int room);

#if UNITTEST==1
int set_light_cycles(int light_number, int cycle_time);
int get_light_cycles(int light_number);
int reset_light_states();
void statemachine_light_control(int light,int *test);
void set_desired_light(int light, int value);
int desired_light(int light);
int set_light_sensor_values(int light, int value);
int get_light_control(int light);
int set_light_state(int light, int ON );
#else
void statemachine_light_control(int light);
#endif

#endif /* STATEMACHINE_H */


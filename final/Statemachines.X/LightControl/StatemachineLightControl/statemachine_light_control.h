
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




int SetTimer(int light);
int GetCycle(int room);

#if UNITTEST==1
int set_light_cycles(int light_number, int cycle_time);
int get_light_cycles(int light_number);
int ResetLightStates();
void Statemachine_LightControl(int light,int *test);
void SetDesiredLight(int light, int value);
int desiredLight(int light);
int SetLightSensorValues(int light, int value);
int GetLightControl(int light);
int SetLightState(int light, int ON );
#else
void Statemachine_LightControl(int light);
#endif

#endif /* STATEMACHINE_H */


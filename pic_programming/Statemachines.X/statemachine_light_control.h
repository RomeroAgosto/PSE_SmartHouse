
/*
 * File:   statemachine.h
 * Author: sascha
 *
 * Created on November 28, 2017, 7:38 PM
 */

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "statemachines.h"

#define TURNED_OFF 0
#define TURNED_ON 1



int SetNewCycle(int room,int new_cycle);
int desiredLight_dummy(int light);
int GetLightControl_dummy(int light);
int SetLightState_dummy(int light, int ON );
int SetTimer(int light);
void Statemachine_LightControl(int light);



#endif /* STATEMACHINE_H */


 /**@file  statemachine_light_control.h
 *      @author Deep Impact
 *      @date 15 Dez 2017
*/

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "../../statemachines.h"

#define TURNED_OFF 0
#define TURNED_ON 1



/**
 *      @brief  set_timer, Counts the seconds till the Cycles [ in seconds ] is reached 1 Cycle <-> 1s, This function is called from the Clock interrupt
 *      @param  light number of the ligths
 */
int set_timer(int light);


#if UNITTEST==1
void set_light_cycles(int light_number, int cycle_time);
int get_light_cycles(int light_number);
int reset_light_states();
void statemachine_light_control(int light,int *test);
void set_desired_light(int light, int value);
int desired_light(int light);
int set_light_sensor_values(int light, int value);
int get_light_control(int light);
int set_light_state(int light, int ON );
#else
/**
 *      @brief  This state machine implements the light control, inside of this function, the decisions are made
 *      @param  light number [in which room]
 *      @states turned on == TRUE and turned_off == FALSE
 */
void statemachine_light_control(int light);
#endif

#endif /* STATEMACHINE_H */


 /**@file  statemachine_water_control.h
 *      @author Deep Impact
 *      @date 15 Dez 2017
*/
#ifndef STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H
#define STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H

#include "../../statemachines.h"


#define DESIRED_TEMPERATURE 0
#define INCREASE_WATER_TEMPERATURE 1


static int water_temp_state=0;/*!<state of water*/

static int upper_threshold_water=65; /*!< the upper_threshold_water is the upper band of the trigger in order to avoid shuttering*/
static int lower_threshold_water=55;/*!< the lower_threshold_water is the upper band of the trigger in order to avoid shuttering*/

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
/**
 *      @brief  This state machine implements the water control, inside of this function, the decisions are made
 *      @states turned on == TRUE and turned_off == FALSE
 */
void statemachine_water_control(void);
#endif



#endif //STATEMACHINE_STATEMACHINE_WATERTEMP_CONTROL_C_H

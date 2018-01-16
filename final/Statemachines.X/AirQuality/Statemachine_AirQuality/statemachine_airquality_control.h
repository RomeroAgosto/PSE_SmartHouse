 /**@file  statemachine_airquality_control.h
 *      @author Deep Impact
 *      @date 15 Dez 2017
*/
#ifndef STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H
#define STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H

#include "../../statemachines.h"

#define GREEN 0
#define YELLOW 1
#define RED 2



/**    
 *      @brief Since the state is protected inside of the function, other functions can get the state thorugh this function
 *      @return returns the current state of the air quality control -> RED/YELLOW/GREEN
 *   
 */
int get_air_quality_state(int room);
/**
 *      @brief  Function sets a alarm, connect to a pin, here a dummy pin
 */

int set_warning(void);

#if UNITTEST == 1
void statemachine_air_quality(int room,int *test);
void set_ventilator_buzzer( int color);
void get_air_quality(int room, int *sensor_values);
void set_air_quality(int room, int *input_values);
void set_light_quality(int room, int color);
void set_ventilator_state(int room,int on);
void reset_air_quality_state(void);
int set_air_quality_hysteresis(int risk_level,int sensor, int value);
int get_air_quality_hysteresis(int risk_level,int sensor);
int set_air_quality_threshold(int risk_level, int threshold, int value);
int get_air_quality_threshold(int risk_level, int threshold);

#else
/**
 *      @brief  This state machine implements the air quality control, inside of this function, the decisions are made
 *      @states The states used to describe the behavior are RED GREEN and YELLOW and they represent the current air quality
 */
void statemachine_air_quality(int room);
#endif

#endif //STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H

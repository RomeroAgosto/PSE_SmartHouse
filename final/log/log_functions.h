/** @file log_functions.h
* @author Deep Impact
* @date 15 Dez 2017
* @brief functions that allow log management
*  
*
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../update/update.h"
#include "../Statemachines.X/AirQuality/Statemachine_AirQuality/statemachine_airquality_control.h"
 
/** 
* @brief this function saves the sensor information and saves it
 * 
*/
 
int log_data_saving();
 
 
/** 
* @brief This functions creates a message with all the information present in the log
* @param  message receve the pointer to put the message
*/
 
int log_create_msg(char *message);
 
/** 
* @brief This functions creates a message with all the information present in the log
* @param  message receve the pointer to put a string
*/
void set_log_flag();
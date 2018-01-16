/** \file log_functions.h
* \brief functions that allow log management
*  
*
* 
*
* \author Rafael Almeida
*
* \date 15-12-2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../update/update.h"
#include "../Statemachines.X/AirQuality/Statemachine_AirQuality/statemachine_airquality_control.h"

/** 
* \brief this function saves the sensor information and saves it
 * \author Rafael Almeida 
* \date 14-12-2017  
*/

int log_data_saving();


/** 
* \brief This functions creates a message with all the information present in the log
* \param  message receve the pointer to put a string
 * \author Rafael Almeida 
* \date 03-11-2017  
*/

int log_create_msg(char *message);

/** 
* \brief This functions creates a message with all the information present in the log
* \param  message receve the pointer to put a string
 * \author Samuel Simoes 
* \date 10-01-2018  
*/
void set_log_flag();
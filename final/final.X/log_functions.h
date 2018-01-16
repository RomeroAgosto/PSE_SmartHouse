/** @file log_functions.h
* @author Deep Impact
* @date 15 Dez 2017
* @brief functions that allow log management
*  
*
*
*/


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
<<<<<<< Updated upstream:final/final.X/log_functions.h
=======

/** 
* @brief This functions creates a message with all the information present in the log
* @param  message receve the pointer to put a string
*/
void set_log_flag();
>>>>>>> Stashed changes:final/log/log_functions.h

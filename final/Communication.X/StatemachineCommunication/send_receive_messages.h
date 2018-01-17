 /**@file  create_normal_message.h
 *      @author Deep Impact
 *      @date 15 Dez 2017
*/
#ifndef COMMUNICATION_SEND_MESSAGES_C_H
#define COMMUNICATION_SEND_MESSAGES_C_H

#include <stdio.h>
#include <stdlib.h>



#include <string.h>
#include "../../schedules/schedules.h"
#include "../../Statemachines.X/Technician/Structure/technician_structure.h"

#define SEND_NO_MESSAGE 0
#define SEND_NEW_STATUS 1
#define SEND_SCHEDULES 2
#define RECEIVE_SCHEDULES 3
#define SEND_DATALOG 4

#define UNITTEST 0


#if UNITTEST==1

#define TRUE 1
void get_message(char *mess);
int get_time(char *message);
int reset_messages();
int create_normal_message(char *message);
void set_message_flag(int flag);
void set_message(char *mess);
int statemachine_communication(int *message);
void send_message(char *send);
int check_received_message(char *message, int p);
#else
#include "../../../final/update/update.h"
#include "../../Statemachines.X/statemachines.h"
#include "create_normal_message.h"
#include "../../log/log_functions.h"
/**
 *      @brief  create a message to send to pc to uptade the data
 *       @param  messege place where the address will be allocated
 */
int create_normal_message(char *message);

/**
 *      @brief  check receve message if right
 *       @param  messege place where the address will be allocated
 *      @param  p position of the cardinal
 */
long int check_received_message(char *message, int p);
/**
 *      @brief  send the messege
 *       @param  messege place where the address will be allocated
 *     
 */
int send_message(char *message);
/**
 *      @brief  This state machine implements the communication control, inside of this function, the decisions are made
 *    
 */
int statemachine_communication(void);

#endif
#endif //COMMUNICATION_SEND_MESSAGES_C_H

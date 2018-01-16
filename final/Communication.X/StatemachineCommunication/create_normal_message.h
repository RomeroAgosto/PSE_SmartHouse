 /**@file  create_normal_message.h
 *      @author Deep Impact
 *      @date 15 Dez 2017
*/

#ifndef COMMUNICATION_CREATE_NORMAL_MESSAGE_H
#define COMMUNICATION_CREATE_NORMAL_MESSAGE_H

#include "send_receive_messages.h"
#include "../../../final/update/update.h"
#include "../../Statemachines.X/statemachines.h"
/**
 *      @brief  create a message to send to pc to uptade the data
 *       @param  messege place where the address will be allocated
 */
int create_normal_message(char *message);

#endif //COMMUNICATION_CREATE_NORMAL_MESSAGE_H

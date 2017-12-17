//
// Created by sascha on 16-12-2017.
//

#ifndef COMMUNICATION_MESSAGE_H
#define COMMUNICATION_MESSAGE_H

#include <stdio.h>
#include "get_schedules.h"

#define SEND_NO_MESSAGE 0
#define SEND_NEW_STATUS 1
#define SEND_SCHEDULES 2
#define RECEIVE_SCHEDULES 3
#define SEND_DATALOG 4


int message_handle(int message_flag,char *message);
int create_normal_message(char *message);
#endif //COMMUNICATION_MESSAGE_H

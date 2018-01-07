//
// Created by sascha on 16-12-2017.
//

#ifndef COMMUNICATION_SEND_MESSAGES_C_H
#define COMMUNICATION_SEND_MESSAGES_C_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "create_normal_message.h"

#define SEND_NO_MESSAGE 0
#define SEND_NEW_STATUS 1
#define SEND_SCHEDULES 2
#define RECEIVE_SCHEDULES 3
#define SEND_DATALOG 4

#define  UNITTEST 1

#if UNITTEST==1
void SetMessageFlag(int flag);
#else
void _UART1Handler(void);

#endif

int Statemachine_Communication(void);
//int create_normal_message(char *message);

/*send messages*/
int get_digits(int score_int, char *score_char);
int send_message(char *message);

/*receive messages*/
long int check_received_message(char *message);
long int get_int(char* received_checksum,int length);
double power(double a, double b);

#endif //COMMUNICATION_SEND_MESSAGES_C_H

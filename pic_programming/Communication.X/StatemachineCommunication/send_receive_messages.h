#ifndef COMMUNICATION_SEND_MESSAGES_C_H
#define COMMUNICATION_SEND_MESSAGES_C_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

#define SEND_NO_MESSAGE 0
#define SEND_NEW_STATUS 1
#define SEND_SCHEDULES 2
#define RECEIVE_SCHEDULES 3
#define SEND_DATALOG 4

#define  UNITTEST 1

#if UNITTEST==1
#define TRUE 1
int reset_messages();
int create_normal_message(char *message);
void SetMessageFlag(int flag);
void SetMessage(char *mess);
int Statemachine_Communication(int *message);
#else
#include "create_normal_message.h"
#include "../../../final/log/log_functions.h"
void _UART1Handler(void);
int Statemachine_Communication(void);

#endif

//int create_normal_message(char *message);
/*send messages*/
int get_digits(int score_int, char *score_char);
int send_message(char *message);

/*receive messages*/
long int check_received_message(char *message);
long int get_int(char* received_checksum,int length);
double power(double a, double b);

#endif //COMMUNICATION_SEND_MESSAGES_C_H

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

#define  UNITTEST 0



#if UNITTEST==1

#define TRUE 1
void GetMessage(char *mess);
int reset_messages();
int create_normal_message(char *message);
void SetMessageFlag(int flag);
void SetMessage(char *mess);
int Statemachine_Communication(int *message);
#else
#include "../../../final/update/update.h"
#include "../../Statemachines.X/statemachines.h"
#include "create_normal_message.h"
#include "../../log/log_functions.h"
void _UART1Handler(void);
int Statemachine_Communication(void);

#endif

//int create_normal_message(char *message);
/*send messages*/
int get_digits(int score_int, char *score_char);
int send_message(char *message);

/*receive messages*/
long int check_received_message(char *message, int p);
long int get_int(char* received_checksum,int length);
double power(double a, double b);

#endif //COMMUNICATION_SEND_MESSAGES_C_H

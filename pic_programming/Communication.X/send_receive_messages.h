//
// Created by sascha on 16-12-2017.
//

#ifndef COMMUNICATION_SEND_MESSAGES_C_H
#define COMMUNICATION_SEND_MESSAGES_C_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*send messages*/
int get_digits(int score_int, char *score_char);
int send_message(char *message);

/*receive messages*/
long int check_received_message(char *message);
long int get_int(char* received_checksum,int length);
double power(double a, double b);

#endif //COMMUNICATION_SEND_MESSAGES_C_H

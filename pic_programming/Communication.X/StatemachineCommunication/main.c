#include "send_receive_messages.h"


#if UNITTEST == 0

#include <plib.h>
#include <p32xxxx.h>
#include "../CKCommon/ConfigBits/config_bits.h" // NOTE!! Must precede project file includes
#include "../CKCommon/UART/uart.h"
#include <proc/p32mx795f512l.h>

#endif
#include <string.h>
#include <stdio.h>
#define _SUPPRESS_PLIB_WARNING 1
//#include <xc.h>

#define SYSCLK  80000000L // System clock frequency, in Hz
#define PBCLOCK 40000000L // Peripheral Bus Clock frequency, in Hz

#define SEND_NO_MESSAGE 0
#define SEND_NEW_STATUS 1
#define SEND_SCHEDULES 2
#define RECEIVE_SCHEDULES 3
#define SEND_DATALOG 4

static int send_flag=SEND_NO_MESSAGE;
static int count_interrupt;
int message_flag;
//char message[5000];
/*
 *
 *
 */

/**
 *      @brief  Developing routine for the pic
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
#define UART_PRIORITY_P 4
#define UART_PRIORITY_S 3
#if RUN == 1
void init_uart(void){

    IFS0bits.U1RXIF = 0;
    IFS0bits.U1TXIF = 0;

    IPC6bits.U1IP = UART_PRIORITY_P;
    IPC6bits.U1IS = UART_PRIORITY_S;

    U1STAbits.URXISEL=0;
    U1STAbits.UTXISEL=0;

    IEC0bits.U1RXIE =1;

}
int message_counter=0;
void __ISR(_UART_1_VECTOR,IPL4AUTO) _UART1Handler(void){
    static int message_counter;
    char charbuf[1];
    charbuf[0]= U1RXREG;
    message[message_counter]=charbuf[0];
    message_counter++;
    if (charbuf[0]=='*'){

        message_flag=TRUE;
        message_counter=0;
    }
    IFS0bits.U1RXIF=0;
    IFS0bits.U1TXIF=0;
}
#endif


int main(int argc, char** argv) {

    // Variable declarations;
    char message[]="#?*";
	int a[2];
    SetMessage(message);
    SetMessageFlag(1);
    int i=0;
    Statemachine_Communication(a);
    return (EXIT_SUCCESS);
}


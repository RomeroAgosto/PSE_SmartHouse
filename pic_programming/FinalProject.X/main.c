#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include "../CKCommon/ConfigBits/config_bits.h"
#include "../CKCommon/UART/uart.h"
#include "../Statemachines.X/statemachines.h"
#include "../Communication.X/send_receive_messages.h"
//#include "../Timer_Clock.X/hallClock.h"
#include <string.h>
#include <stdio.h>
#define SYSCLK  80000000L // System clock frequency, in Hz
#define PBCLOCK 40000000L // Peripheral Bus Clock frequency, in Hz

#define SEND_NO_MESSAGE 0
#define SEND_NEW_STATUS 1
#define SEND_SCHEDULES 2
#define RECEIVE_SCHEDULES 3
#define SEND_DATALOG 4

static int send_flag=SEND_NO_MESSAGE;
static int count_interrupt;
extern struct tm time_hall;

#include "../sensor_struct/struct_lib.h"


/**
 *      @brief  Developing routine for the pic
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
char message[500];

void run_alonsideWClock(void){
    SetTimer(0);
    SetTimer(1);
    SetTimer(2);
    SetTimer(3);
}

int main(int argc, char** argv) {
    
    // Variable declarations;
    int i=0;

    // Performance optimization (flash access time, enable instruct and data cache,... and PBClock setup
    SYSTEMConfigPerformance(SYSCLK);
    mOSCSetPBDIV(OSC_PB_DIV_2); // This is necessary since SYSTEMConfigPerformance defaults FPBDIV to DIV_1

    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
    INTEnableInterrupts();

    // Set RA3 as outpout
    TRISAbits.TRISA3 = 0;
    
    UartInit(PBCLOCK,115200);
    _mon_putc('a');
    _mon_putc('\n');
    //setup_clockHall(&run_alonsideWClock);
    init_uart();
    /*timer initialization*/    
    PORTAbits.RA3=0;
    while(1){
        Statemachine_AirQuality();
        Statemachine_LightControl(1);
        message_handle();
       
            //message_handle(1);
    }
        
    return (EXIT_SUCCESS);
}


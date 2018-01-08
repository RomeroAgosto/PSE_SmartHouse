#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include "../CKCommon/ConfigBits/config_bits.h"
#include "../CKCommon/UART/uart.h"
//#include "../Schedules.X/desiredValues.h"
//#include "../Statemachines.X/statemachines.h"
//#include "../Communication.X/send_receive_messages.h"
#include "../Timer_Clock.X/hallClock.h"
#include <string.h>
#include <stdio.h>


#define SYSCLK  80000000L // System clock frequency, in Hz
#define PBCLOCK 40000000L // Peripheral Bus Clock frequency, in Hz

static int count_interrupt;
extern struct tm time_hall;

//#include "../sensor_struct/struct_lib.h"


/**
 *      @brief  Developing routine for the pic
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */

void run_alonsideWClock(void){
/*    SetTimer(0);
    SetTimer(1);
    SetTimer(2);
    SetTimer(3);*/
}

//#include "../Schedules.X/schedules.h"

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
    setup_clockHall(&run_alonsideWClock);
    
    _mon_putc('a');
    _mon_putc('\n');
    //init_uart();
     
    /*timer initialization*/    
    /*PORTAbits.RA3=0;
    while(1){
        updateSensors();
        print();
        //delay(500);
        
        Statemachine_AirQuality();
        for(i=0;i<4;i++){
            Statemachine_LightControl(i);
        }
        message_handle();
    }
        */
    return (EXIT_SUCCESS);
}


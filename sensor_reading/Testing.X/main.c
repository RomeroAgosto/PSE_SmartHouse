/* 
 * File:   main.c
 * Author: Ricardo
 *
 * Created on 17 December 2017, 00:06
 */
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
//#include <sys/attribs.h>

#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>

#define SYSCLK  80000000L   // System clock frequency, in Hz
#define PBCLOCK 40000000L   // Peripheral bus clock

#include <p32xxxx.h>
#include "update.h"

#include "../../pic_programming/CKCommon/ConfigBits/config_bits.h"
#include "../../pic_programming/CKCommon/UART/uart.h" 
#include "adc_init.h"
/*
 * 
 */

void delay(unsigned int dms){
    unsigned int t;
    t=ReadCoreTimer()+40000*dms;
    while(ReadCoreTimer() < t);
}

int main() {
    // Performance optimization (flash access time, enable instruct and data cache,... and PBClock setup
    SYSTEMConfigPerformance(SYSCLK);
    mOSCSetPBDIV(OSC_PB_DIV_2); // This is necessary since SYSTEMConfigPerformance defaults FPBDIV to DIV_1

    // Set RA3 as outpout
    TRISAbits.TRISA3 = 0;

    
    
    
                // Init UART
    if(UartInit(PBCLOCK,115200) != UART_SUCCESS) {
            PORTAbits.RA3 = 1;
            while(1);
    }
/*timer initialization*/    

    //setup_clockHall(NULL);
    PORTAbits.RA3=0;

    __XC_UART = 1; /* Redirect stdin/stdout/stderr to U
     printf("timer init\n");ART1*/
    
    /*int temperature[8];
    int air_quality[5];
    int motion[4];*/
    adc_init();
    //int temp_room[6];//humi_room[2];
    // air_quality_room[4];//motion_detected[2];
    while(1) {
        valuesinti();
        updateSensors();
        print();
        delay(500);
    }
    return (EXIT_SUCCESS);
}


/* 
 * File:   main
 * Author: Bruno
 *
 * Created on Oct 25, 2017
 * MPLAB X IDE v4.01 + XC32 v1.44
 *
 *      
 *
 */

#include "config_bits.h" // NOTE!! Must precede project file includes

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include "uart.h" 
#include "sr.h"
#include "struct_lib.h"

#define SYSCLK  80000000L // System clock frequency, in Hz
#define PBCLOCK 40000000L // Peripheral Bus Clock frequency, in Hz

/*
 * 
 */

void delay(unsigned int dms){
    unsigned int t;
    t=ReadCoreTimer()+40000*dms;
    while(ReadCoreTimer() < t);
}

int main(int argc, char** argv) {
    // Performance optimization (flash access time, enable instruct and data cache,... and PBClock setup
    SYSTEMConfigPerformance(SYSCLK);
    mOSCSetPBDIV(OSC_PB_DIV_2); // This is necessary since SYSTEMConfigPerformance defaults FPBDIV to DIV_1

    // Set RA3 and D5 ports
    TRISAbits.TRISA3 = 0;  // A3 as output
    TRISDbits.TRISD5 = 0; // D5 a output
    ODCDbits.ODCD5 = 1; // D5 as open-drain

    // Init UART and redirect tdin/stdot/stderr to UART
    if(UartInit(PBCLOCK, 115200) != UART_SUCCESS) {
        PORTAbits.RA3 = 1;
        while(1);
    }
    __XC_UART = 1; /* Redirect stdin/stdout/stderr to UART1*/
    
    int t[6];
    int a[4];
    int motion_detected[2];
    //int temp_room[6];//humi_room[2];
    // air_quality_room[4];//motion_detected[2];
    int i=0,j=0;
    while (1) {
        for (i=0; i<6; i++){
            temp(t);
            if(i<4){
                air_quality_level(a);
                if(i<2)
                    motion_detected[i]=motion_detection(i);
            }
        }
        /*for (i=4; i<6; i++){
            temp_room[temp_digital(i+1);
        }*/
        for (i=0; i<6; i++){
            printf("%s", "Room ");
            printf("%d\n",i+1);
            printf("%s","   Temperature (C):");
            printf("%i\n\r",t[i]);
            delay(500);
        }
        printf("%s","   PM10 concentration:");
        printf("%i\n\r",a[0]);
        delay(500);
        printf("%s","   C02 concentration:");
        printf("%i\n\r",a[1]);
        delay(500);
        printf("%s","   CO concentration:");
        printf("%i\n\r",a[2]);
        delay(500);
        printf("%s","   O3 concentration:");
        printf("%i\n\r",a[3]);
        delay(500);
        for(i=0; i<2;i++){
            printf("%s","   Motion:");
            printf("%i\n\r ",motion_detected[i]);
            delay(500);
        }
    }
    return (EXIT_SUCCESS);
}





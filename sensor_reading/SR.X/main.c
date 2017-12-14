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
    
    double temp_room[6],humi_room[2],*p;
    char air_quality_room[4],motion_detected[2];
    int i,j=0;
    while (1) {
        
        for (i=0; i<4; i++){
            temp_room[i]=temp_analog(i+1);
            //air_quality_room[i]=air_quality_level(i);
        }
        for (i=4; i<6; i++){
            temp_room[i]=temp_digital(i);
            //motion_detected[i-4]=motion_detection(i-4);
        }
        /*for (i=6; i<8; i++){
            p=humidity_temperature(i);
            humi_room[i-6]=*(p+j);
            j++;
            temp_room[i]=*(p+j);
            j=0;
        }*/

        // __XC_UART = 1; /* Redirect stdin/stdout/stderr to UART1*/
        for (i=0; i<6; i++){
            printf("%s", "Room ");
            printf("%d\n p",i+1);
            printf("%s","Temperature (C):");
            printf("%f\n\r",temp_room[i]);
            
            delay(500);
        }
        /*for (i=0; i<2; i++){
            printf("Room %d : /n", i);
            printf("    Humidity: %d (%)",humi_room[i]);
            //printf("    Presence: %c ",motion_detected[i]);
            delay(500);
        }*/
        /*for (i=0; i<4; i++){
            printf("Room %d : /n", i);
            printf("    Air quality: %c ",air_quality_room[i]);
            delay(500);
        }*/
    }
    return (EXIT_SUCCESS);
}





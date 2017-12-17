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

    // Init UART and redirect tdin/stdot/stderr to UART
    if(UartInit(PBCLOCK, 115200) != UART_SUCCESS) {
        PORTAbits.RA3 = 1;
        while(1);
    }
    __XC_UART = 1; /* Redirect stdin/stdout/stderr to UART1*/
    
    /*int temperature[8];
    int air_quality[5];
    int motion[4];*/
    adc_init();
    //int temp_room[6];//humi_room[2];
    // air_quality_room[4];//motion_detected[2];
    int i=0,j=0;
     
    while(1){
        static int p[9];
        static int air_quality[20];
        air_temp_analog(p);
        for (i=0; i<6; i++){
                printf("%s", "Room ");
                printf("%d\n",i+1);
                printf("%s","   Air Temperature (C):");
                printf("%d\n\r",p[i]);
                delay(500);
        }

        water_temp_analog(p);

        printf("%s","   Water Temperature (C):");
        printf("%i\n\r",p[6]);
        delay(500);

        temp_digital(p);
        
        for (i=7; i<9; i++){
                printf("%s", "Room ");
                printf("%d\n",i+1);
                printf("%s","  Digital air Temperature (C):");
                printf("%i\n\r",p[i]);
                delay(500);
        }

        air_quality_level(air_quality);

        for(j=0;j<5;j++){
            
            printf("%s", "Room ");
            printf("%d\n", j+1);
            
            printf("%s","   PM10 concentration (ug/m3):");
            printf("%d\n\r",air_quality[0+4*j]);
           
            printf("%s","   C02 concentration (ppm):");
            printf("%d\n\r",air_quality[1+4*j]);

            printf("%s","   CO concentration (ppm):");
            printf("%d\n\r",air_quality[2+4*j]);

            printf("%s","   O3 concentration (ppm):");
            printf("%d\n\r",air_quality[3+4*j]);

            printf("%s","   Humidity (%):");
            printf("%d\n\r",air_quality[4+4*j]);
            delay(2000);
        }

        motion_detection(p);

        for(i=0; i<4;i++){
            printf("%s","   Motion:");
            printf("%i\n\r ",p[i]);
            delay(500);
        }
    }
    return (EXIT_SUCCESS);
}





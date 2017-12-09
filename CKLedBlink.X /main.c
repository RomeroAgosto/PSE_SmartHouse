/* 
 * File:   CKLedBlink.c
 * Author: Paulo Pedreiras
 *
 * Created on Oct 25, 2017
 * MPLAB X IDE v3.50 + XC32 v1.42
 *
 * Target: Digilent chipKIT MAx32 board 
 * Configurations:
 *      HSPLL; CPUCLK=80MHz, PBCLCK=40MHz; Watchdog timer disabled
 *      
 * Overview:
 *      Blinks led connected on port RA3 (Digital pin 13 of the chipKIT board)
 *      Inits the UART (U1A, 115200, 8,n,1) and sends '*' when the led toggles
 *
 *  Revisions:
 *      2017-10-15: Initial release
 */

#include "../CKCommon/ConfigBits/config_bits.h" // NOTE!! Must precede project file includes
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include "../CKCommon/UART/uart.h" 
#include <string.h>

#define SYSCLK  80000000L // System clock frequency, in Hz
#define PBCLOCK 40000000L // Peripheral Bus Clock frequency, in Hz


/*
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

int identify(char *input){
    
    if(input[1]=='T'){
        int upper_threshold=60;
        if(input[2]=='1'){
            upper_threshold=input[2]*10;
            upper_threshold=upper_threshold+input[3];                             
        }
        return upper_threshold;
    }
    
    
    
}

int main(int argc, char** argv) {
    // Variable declarations;
    int i, j;

    // Performance optimization (flash access time, enable instruct and data cache,... and PBClock setup
    SYSTEMConfigPerformance(SYSCLK);
    mOSCSetPBDIV(OSC_PB_DIV_2); // This is necessary since SYSTEMConfigPerformance defaults FPBDIV to DIV_1

    // Set RA3 as outpout
    TRISAbits.TRISA3 = 0;
    PORTAbits.RA3=0;

    // Init UART
    if(UartInit(PBCLOCK,9600) != UART_SUCCESS) {
        PORTAbits.RA3 = 1;
        while(1);
    }
    char input[10];
    GetChar(input);
    // Loop
    int k=0;
    while(k<0){
   // Statemachine_WaterControl(identify(input));
    for(i=0;i<100000;i++){ 
        for(j=0;j<100;j++){
        }
        }
    k++;
    }
    
    while (1) {
            char to_send[]="#T120*";
            send_messages(to_send);
          /*  GetChar(input);
            if (input[0]=='k'){
                PORTAbits.RA3=!PORTAbits.RA3;
            }*/

    }

    return (EXIT_SUCCESS);
}


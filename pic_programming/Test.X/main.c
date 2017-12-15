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
//#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include <p32xxxx.h>
#include "../CKCommon/UART/uart.h"
#include "statemachine_light_control.h"
#include "statemachine_airquality_control.h" 
#include <string.h>
#include <stdio.h>
//#include "timer_libs.h"
#include "../clock_hall/hallClock.h"

#define TIMER 1

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
sensorvalues ola;
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

int read_input(char *input){
    char check_input[2];
    char waiting[]="waiting\n";
    /*do{
      
        GetChar(check_input);
        send_messages(waiting);
    } while (check_input[0]!='#');
    char char_bit[1];
    int i=0;
    do{
        GetChar(char_bit);
        if (char_bit[0]!=input[i]){strcat(input,char_bit);}/* PIC reads to fast!*/
     /*   i++;
    }while(char_bit[0]!='*');
    send_messages(input);*/
    *input='a';//dummy
    return 1;
}

int Send_Message(){
    return 1;
}
/**
 *      @brief  This function will run alongside the clock hall
 *     @author  Samuel Simoes, samuelmsimoes@ua.pt
 *     Created  20-Set-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
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

    // Set RA3 as outpout
    TRISAbits.TRISA3 = 0;

    
    
    
                // Init UART
    if(UartInit(PBCLOCK,115200) != UART_SUCCESS) {
            PORTAbits.RA3 = 1;
            while(1);
    }
/*timer initialization*/    

    setup_clockHall(&run_alonsideWClock);
    PORTAbits.RA3=0;

    printf("timer init\n");
#if 1
    
    /*read message -> set a flag corresponding to the input*/
    char input[1];
    read_input(input);
    
    char to_send[500]; 
    while(1){ /*endless loop in the end*/
        /*start the message*/
        /*checking the input in the beginning and setting flags*/
        if (GetChar(input) != 0){
            if (input[0]=='?'){  
                /* New status sends the current sensor values*/
                send_flag=SEND_NEW_STATUS;
            }
            else if(input[0]=='!'){
                /*sends the current schedule*/
                send_flag=SEND_SCHEDULES;
            }
            else if(input[0]=='+'){
                /*receive a new schedule*/
                send_flag=RECEIVE_SCHEDULES;
            }
            else if(input[0]=='%'){
                /*send a Datalog to the pc side*/
                send_flag=SEND_DATALOG;
            }                
        }            
       
        /*water temperature control*/
        Statemachine_WaterControl(60,to_send);
        
        /*light control*/
        Statemachine_LightControl(0,to_send);
        Statemachine_LightControl(1,to_send);
        Statemachine_LightControl(2,to_send);
        Statemachine_LightControl(3,to_send);
        
        /*Air Quality*/
        Statemachine_AirQuality(to_send);
        
        /*Airtemperature Control*/
        int k;
        for(k=0;k<4;k++) {
           // Statemachine_AirControl(k, to_send,25);
        }
    }
#endif
    char test[]="test message";
    send_message(test);

    return (EXIT_SUCCESS);
}


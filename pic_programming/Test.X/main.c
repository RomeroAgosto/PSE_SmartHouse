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
#include "statemachine_light_control.h"
#include "statemachine_airquality_control.h" 
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
    do{
      
        GetChar(check_input);
        send_messages(waiting);
    } while (check_input[0]!='#');
    char char_bit[1];
    int i=0;
    do{
        GetChar(char_bit);
        if (char_bit[0]!=input[i]){strcat(input,char_bit);}/* PIC reads to fast!*/
        i++;
    }while(char_bit[0]!='*');
    send_messages(input);
}

int main(int argc, char** argv) {
    // Variable declarations;
    int i=0, j;

    // Performance optimization (flash access time, enable instruct and data cache,... and PBClock setup
    SYSTEMConfigPerformance(SYSCLK);
    mOSCSetPBDIV(OSC_PB_DIV_2); // This is necessary since SYSTEMConfigPerformance defaults FPBDIV to DIV_1

    // Set RA3 as outpout
    TRISAbits.TRISA3 = 0;
    PORTAbits.RA3=0;
            // Init UART
    if(UartInit(PBCLOCK,115200) != UART_SUCCESS) {
            PORTAbits.RA3 = 1;
            while(1);
    }

    /*read message*/
    char input[1];
    //read_input(input);
    
    
    while(i<1){ /*endless loop in the end*/
        /*start the message*/
        /*checking the input in the beginning and setting flags*/
        if (GetChar(input) != 0){
            if (input[0]=='?'){  
                send_flag=SEND_NEW_STATUS;
            }
            else if(input[0]=='!'){
                send_flag=SEND_SCHEDULES;
            }
            else if(input[0]=='+'){
                send_flag=RECEIVE_SCHEDULES;
            }
            else if(input[0]=='%'){
                send_flag=SEND_DATALOG;
            }                
        }            
        
        char *to_send=malloc(500); 
        strcpy(to_send,"#{\n");
        
        /*water temperature control*/
        char add_temperature[]="  \"WaterTemperature\":[\n";
        strcat(to_send,add_temperature); /*append the string*/
        Statemachine_WaterControl(60,to_send);
        
        /*light control*/
        char add_light[]=""
        "\"Light\":[\n"
        "   {\n";
        strcat(to_send,add_light); /*append the string*/
        Statemachine_LightControl(0,to_send);
        Statemachine_LightControl(1,to_send);
        Statemachine_LightControl(2,to_send);
        Statemachine_LightControl(3,to_send);
        char stop_light[]=""
        "   }]\n";
        strcat(to_send,add_light); /*append the string*/
        
        /*Air Quality*/
        char add_airquality[]="\"AirQuality\":[\n";
        strcat(to_send,add_airquality); /*append the string*/
        Statemachine_AirQuality(to_send);
        
        /*Airtemperature Control*/
        strcat(to_send,"{\"AirTemperature\":[\n{\n");
        int k;
        for(k=0;k<4;k++) {
            Statemachine_AirControl(k, to_send,25);
        }
        /*add the delimiter and send the message*/
        char add_end_delimiter[5];
        sprintf(add_end_delimiter,"}*"); /*EndDelimiter*/
        strcat(to_send,add_end_delimiter); /*append the string*/
        
        /* send the message*/
        send_messages(to_send);
        i++;
        free(to_send);
    }
    
    

    return (EXIT_SUCCESS);
}


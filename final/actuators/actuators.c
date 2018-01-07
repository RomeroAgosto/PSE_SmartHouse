
#include "actuators.h"
#include <p32xxxx.h>
#include <stdio.h>
int setLight(int n_light, int state) 
{
    if(n_light==0){  
        PORTEbits.RE4=state;
    }
    else if(n_light==1){  
        PORTEbits.RE1=state;
    }
    else if(n_light==2){  
        PORTEbits.RE2=state;
    }
    else if(n_light==3){  
        PORTEbits.RE3=state;
    }
    return 0;
}

int setVentilatorBuzzer(int state) {
    if(state==GREEN){
        PORTE=PORTE & 0xff9f;
    }
    else if(state==YELLOW) {
        PORTE=(PORTE & 0xffbf) | 0x0020;
    }
    else if(state==RED) {
        PORTE=PORTE | 96;
        
    }
}

int SetHeater(int room, int state){
    if (room==0){
        LATAbits.LATA0=state;
        PORTAbits.RA0=state;
    }
    else if (room == 1){
        LATAbits.LATA1=state;
        PORTAbits.RA1=state;
    }
    else if (room == 2){
        LATAbits.LATA2=state;
        PORTAbits.RA2=state;
    }
    else if (room == 3){
        LATAbits.LATA3=state;
        PORTAbits.RA3=state;
    }
    else if (room == 4){
        LATAbits.LATA4=state;
    }
    else if (room == 5){
        LATAbits.LATA5=state;
    }
    else if (room == 6){
        PORTAbits.RA5=state;
    }
    else if (room == 7){
        PORTAbits.RA5=state;
    }    
}
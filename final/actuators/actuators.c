
#include "actuators.h"

int set_water_heater(int state) {
    PORTEbits.RE8=state;
    return 0;
}

int set_light(int n_light, int state) 
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

int set_ventilator_buzzer(int state) {
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

int set_heater(int room, int state){
    //printf("room %d turned %d\n",room,state);
    if (room==0){
        PORTAbits.RA9=state;
    }
    else if (room == 1){
        PORTAbits.RA10=state;
    }
    else if (room == 2){
        PORTAbits.RA2=state;
    }
    else if (room == 3){
        PORTAbits.RA3=state;
    }
    else if (room == 4){
        PORTAbits.RA4=state;
    }
    else if (room == 5){
        PORTAbits.RA5=state;
    }
    else if (room == 6){
        PORTAbits.RA6=state;
    }
    else if (room == 7){
        PORTAbits.RA7=state;
    }    
}
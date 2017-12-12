#include "statemachine_watertemp_control.h"
#define DEVELOP 0

#if DEVELOP == 1 //structure just as a dummy for the registers
struct PORTA{
    int RA0;
    int RA1;
    int RA2;
    int RA3;
};
struct PORTA PORTAbits;
#endif


int SetHeatingWater(int Command){
    if (Command==TRUE);//{printf("water turned on\n");}
    else {}//printf("water turned off \n");}
    return 1; /*we should introduce a check, if this procedure was successful */
}

int GetWaterTemperature(){
    return 55; /* dummy which returns a temperature to check the behaviour of the state machine*/
}

void Statemachine_WaterControl(int desired_temperature,char *to_send) {
    int water_temperature=GetWaterTemperature();
    PORTAbits.RA3=0; // remove that later again!
    upper_threshold=desired_temperature+5; /*trigger band is 10 degrees!*/
    lower_threshold=desired_temperature-5;
    /* states are stored in the states variables. so higher function can easily access the current states*/
    switch (water_temp_state) {

        case DESIRED_TEMPERATURE:
            SetHeatingWater(FALSE);
            if (water_temperature<desired_temperature){water_temp_state=INCREASE_WATER_TEMPERATURE;} /*Implementation of Schmitt -Trigger misses here*/
            break;

        case INCREASE_WATER_TEMPERATURE:
            SetHeatingWater(TRUE);
            PORTAbits.RA3=!PORTAbits.RA3;
            if (water_temperature>desired_temperature){water_temp_state=DESIRED_TEMPERATURE;}
            break;
        default:
            SetHeatingWater(FALSE);
            break;
    }
    char add_to_message[80];/*take care that enough storage is available*/
    sprintf(add_to_message,""
            "   {\n"
            "     \"DesiredWaterTemp\":%d,\n"
            "     \"WaterTemp\":%d,\n"
            "     \"WaterState\":%d,\n"
            "   }]\n",desired_temperature,water_temperature,water_temp_state); /*make a string*/
    strcat(to_send,add_to_message); /*append the string*/
}
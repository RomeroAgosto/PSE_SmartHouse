#include "statemachine_watertemp_control.h"
#include <string.h>


int SetHeatingWater(int Command){
    if (Command==TRUE);//{printf("water turned on\n");}
    else {}//printf("water turned off \n");}
    return 1; /*we should introduce a check, if this procedure was successful */
}

int GetWaterTemperature(){
    return 55; /* dummy which returns a temperature to check the behaviour of the state machine*/
}
void Statemachine_WaterControl(int upper_threshold,char *to_send) {
    int water_temperature=GetWaterTemperature();
    /* states are stored in the states variables. so higher function can easily access the current states*/
    switch (water_temp_state) {

        case DESIRED_TEMPERATURE:
            SetHeatingWater(FALSE);
            if (water_temperature<upper_threshold){water_temp_state=INCREASE_WATER_TEMPERATURE;} /*Implementation of Schmitt -Trigger misses here*/
            break;

        case INCREASE_WATER_TEMPERATURE:
            SetHeatingWater(TRUE);
            PORTAbits.RA3=!PORTAbits.RA3;
            if (water_temperature>upper_threshold){water_temp_state=DESIRED_TEMPERATURE;}
            break;
        default:
            SetHeatingWater(FALSE);
            break;
    }
    char add_to_message[80];/*take care that enough storage is available*/
    sprintf(add_to_message,""
            "   {\n"
            "     \"WaterTempThreshold\":%d,\n"
            "     \"WaterTemp\":%d,\n"
            "     \"WaterState\":%d,\n"
            "   }]\n",upper_threshold,water_temperature,water_temp_state); /*make a string*/
    strcat(to_send,add_to_message); /*append the string*/
}
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
    return 50; /* dummy which returns a temperature to check the behaviour of the state machine*/
}

void Statemachine_WaterControl(int desired_temperature) {
    int water_temperature=GetWaterTemperature();
    upper_threshold_water=desired_temperature+5; /*trigger band is 10 degrees!*/
    lower_threshold_water=desired_temperature-5;
    /* states are stored in the states variables. so higher function can easily access the current states*/
    switch (water_temp_state) {

        case DESIRED_TEMPERATURE:
            SetHeatingWater(FALSE);
            if (water_temperature<lower_threshold_water){water_temp_state=INCREASE_WATER_TEMPERATURE;} /*Implementation of Schmitt -Trigger misses here*/
            break;

        case INCREASE_WATER_TEMPERATURE:
            SetHeatingWater(TRUE);
            if (water_temperature>upper_threshold_water){water_temp_state=DESIRED_TEMPERATURE;}
            break;
        default:
            SetHeatingWater(FALSE);
            break;
    }
}
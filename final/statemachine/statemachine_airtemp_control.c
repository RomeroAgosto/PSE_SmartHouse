#include "statemachine_airtemp_control.h"
#include "../final.X/update.h"
#include "../final.X/actuators.h"

static int desired_temp;

void Statemachine_AirControl(int room) {
    int air_temperature=GetAirTemperature(room);
    desired_temp=desiredAirTemperature(room);/* defined nd desiredValues.h*/
    lower_threshold_air=desired_temp-1;/*two degree trigger-band*/
    upper_threshold_air=desired_temp+1;
    //printf("i'm going into state: %d\n",air_temp_state[room]);
    /* states are stored in the states variables. so higher function can easily access the current states*/
    switch (air_temp_state[room]) {

        case DESIRED_TEMPERATURE:
//            SetHeatingAir(FALSE);
            /*set next state*/
            if (air_temperature<lower_threshold_air){air_temp_state[room]=INCREASE_AIR_TEMPERATURE;} /*If the values drops below the lower threshold increase! -> Avoid shutter*/
            break;

        case INCREASE_AIR_TEMPERATURE:
//            SetHeatingAir(TRUE);
            /*set next state*/
            if(air_temperature>lower_threshold_air){air_temp_state[room]=DESIRED_TEMPERATURE;} /* If the value exceeds the threshold, turn off -> avoid shutter*/
            break;

        default:
 //           SetHeatingAir(FALSE);
            /*SetWarning();something that declares that something went wrong*/
            break;
    }

}
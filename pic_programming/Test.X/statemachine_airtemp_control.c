#include "statemachine_airtemp_control.h"

int SetVentilation(int on){
    if (on==TRUE){printf("Ventilation on\n");}
    else {printf("Ventilation turned off \n");}
    return 1;
}
int SetHeatingAir(int on){
    if (on==TRUE){printf("air heating turned on\n");}
    else {printf("air heating turned off \n");}
    return 1; /*we should introduce a check, if this procedure was successful */
}

int GetAirTemperature(){
    return 20; /* dummy which returns a temperature to check the behaviour of the state machine*/
}

/**
 *      @brief  This state machine implements the air temperature control
 *      @states The states used to describe the behavior are the DESIRED TEMPERATURE, INCREASE TEMPERATURE and DECREASE TEMPERATURE and they represent the current air temperature
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
void Statemachine_AirControl(int room, char*to_send, int desired_temp) {
    int air_temperature=GetAirTemperature();

    lower_threshold_air=desired_temp-1;/*two degree trigger-band*/
    upper_threshold_air=desired_temp+1;
    printf("i'm going into state: %d\n",air_temp_state[room]);
    /* states are stored in the states variables. so higher function can easily access the current states*/
    switch (air_temp_state[room]) {

        case DESIRED_TEMPERATURE:
            SetHeatingAir(FALSE);
            /*set next state*/
            if (air_temperature<lower_threshold_air){air_temp_state[room]=INCREASE_AIR_TEMPERATURE;} /*If the values drops below the lower threshold increase! -> Avoid shutter*/
            break;

        case INCREASE_AIR_TEMPERATURE:
            SetHeatingAir(TRUE);
            /*set next state*/
            if(air_temperature>lower_threshold_air){air_temp_state[room]=DESIRED_TEMPERATURE;} /* If the value exceeds the threshold, turn off -> avoid shutter*/
            break;

        default:
            SetHeatingAir(FALSE);
            /*SetWarning();something that declares that something went wrong*/
            break;
    }
    char add_to_message[150];
    sprintf(add_to_message,"\"Room_%d_Temperature\":%d,\n" /*generate a string for the message*/
            "\"Room_%d_state\":%d,\n"
            "\"Room_%d_lower_threshold\":%d,\n"
            "\"Room_%d_upper_threshold\":%d,\n",room,air_temperature,room,air_temp_state[room],room,lower_threshold_air,room,upper_threshold_air);
    strcat(to_send,add_to_message); /*append the string*/
    printf("the state machine for air control room[%d] switches to state: %d\n",room, air_temp_state[room]);
}
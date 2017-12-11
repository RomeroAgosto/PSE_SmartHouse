
#include "statemachine_airtemp_control.h"
#include "statemachine_airquality_control.h" /* to obtain the current state*/
#include <string.h>
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
    int air_quality=GetAirQualityState();

    lower_threshold_air=desired_temp-1;/*one degree failure is ok*/
    upper_threshold_air=desired_temp+1;
    printf("i'm going into state: %d\n",air_temp_state[room]);
    /* states are stored in the states variables. so higher function can easily access the current states*/
    switch (air_temp_state[room]) {

        case DESIRED_TEMPERATURE:
            SetHeatingAir(FALSE);
            if(air_quality==0){SetVentilation(FALSE);}/* it is just possible to turn off the ventilation when the Air quality is good!*/

            /*set next state*/
            if (air_temperature<lower_threshold_air){air_temp_state[room]=INCREASE_AIR_TEMPERATURE;} /*Implementation of Schmitt -Trigger misses here*/
            else if(air_temperature>upper_threshold_air){air_temp_state[room]=DECREASE_AIR_TEMPERATURE;}
            break;

        case INCREASE_AIR_TEMPERATURE:
            SetHeatingAir(TRUE);
            if(air_quality==0){SetVentilation(FALSE);}/*it is just possible to turn off the ventilation when the Air quality is good!*/

            /*set next state*/
            if (air_temperature>upper_threshold_air){air_temp_state[room]=DECREASE_AIR_TEMPERATURE;} /*if this happened to often, call the technician to adjust the control parameter*/
            else if(air_temperature>lower_threshold_air){air_temp_state[room]=DESIRED_TEMPERATURE;}
            break;

        case DECREASE_AIR_TEMPERATURE:
            SetHeatingAir(FALSE);
            SetVentilation(TRUE);

            /*set next state*/
            if (air_temperature<upper_threshold_air){air_temp_state[room]=DESIRED_TEMPERATURE;}
            else if(air_temperature<lower_threshold_air){air_temp_state[room]=INCREASE_AIR_TEMPERATURE;}/*if this happened to often, call the technician to adjust the control parameter*/
            break;

        default:
            SetHeatingAir(FALSE);
            SetVentilation(FALSE);
            /*SetWarning();something that declares that something went wrong*/
            break;
    }
    char add_to_message[150];
    sprintf(add_to_message,""
            "     \"Room_%dTemperature\":%d,\n"
            "     \"Room_%dState\":%d,\n"
            "     \"Room_%dLower_threshold\":%d,\n"
            "     \"Room_%dUpper_threshold\":%d,\n",room,air_temperature,room,air_temp_state[room],room,lower_threshold_air,room,upper_threshold_air);
    strcat(to_send,add_to_message); /*append the string*/
}
#include "statemachine_airquality_control.h"
#include <string.h>

int SetLightQuality(int color){
   // printf("Color output is: %d\n", color);
};
/**
 *      @brief  enables other functions to obtain the current state of the air quality
 *      @return returns the current state of the air quality control
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
int GetAirQualityState(){
    return air_quality_state;
}
int GetAirQuality(){
    return 20; /* dummy which returns a temperature to check the behaviour of the state machine*/
}

/**
 *      @brief  This state machine implements the air quality control
 *      @states The states used to describe the behavior are RED GREEN and YELLOW and they represent the current air quality
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
void Statemachine_AirQuality(char* to_send) {
    int air_quality=GetAirQuality();

    /* states are stored in the states variables. so higher function can easily access the current states*/
    switch (air_quality_state) {

        case GREEN:
            SetLightQuality(GREEN);
            SetVentilation(FALSE);/* it is just possible to turn off the ventilation when the Air quality is good!*/

            /*set next state*/
            if (air_quality<LOWER_THRESHOLD_AIR_QUALITY){air_quality_state=RED;}
            else if(air_quality<UPPER_TRHESHOLD_AIR_QUALITY){air_quality_state=YELLOW;}
            break;

        case YELLOW:
            SetLightQuality(YELLOW);
            SetVentilation(TRUE);

            /*set next state*/
            if (air_quality<LOWER_THRESHOLD_AIR_QUALITY){air_quality_state=RED;} /*if this happened to often, call the technician to adjust the control parameter*/
            else if(air_quality>UPPER_TRHESHOLD_AIR_QUALITY){air_quality_state=GREEN;}
            break;

        case RED:
            SetLightQuality(RED);
            SetVentilation(TRUE);

            /*set next state*/
            if (air_quality>UPPER_TRHESHOLD_AIR_QUALITY){air_quality_state=GREEN;}/* has to be checked first, because we wouldn't check this case the other way round*/
            else if(air_quality>LOWER_THRESHOLD_AIR_QUALITY){air_quality_state=YELLOW;}/*if this happened to often, call the technician to adjust the control parameter*/
            break;

        default:
            SetLightQuality(GREEN);
            SetVentilation(FALSE);
            /*SetWarning();something that declares that something went wrong*/
            break;
    }
    char add_to_message[250];
    sprintf(add_to_message,"   {\n"
            "       \"AirQualityValue\":%d,\n"
            "       \"AirQualityUpperThreshold\":%d,\n"
            "       \"AirQualityLowerThreshold\":%d,\n"
            "     }]\n",air_quality,UPPER_TRHESHOLD_AIR_QUALITY,LOWER_THRESHOLD_AIR_QUALITY);
    strcat(to_send,add_to_message); /*append the string*/
}
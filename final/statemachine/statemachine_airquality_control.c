#include "statemachine_airquality_control.h"
#include <string.h>
#include "../actuators/actuators.h"

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
int GetAirQualityState(int n_air){
    int p[5];
    GetAirQuality(n_air, p);
    
    
    if(p[0] > 65 || p[1] > 5000 || p[2] > 200 || p[3] > 200) {
        return RED;
    }
    else if(p[0] > 20 || p[1] > 600 || p[2] > 25 || p[3] > 100) {
        return YELLOW;
    }
    return GREEN;
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
void Statemachine_AirQuality() {
    /* states are stored in the states variables. so higher function can easily access the current states*/
    int i;
    int tmp=GREEN;
    switch (air_quality_state) {

        case GREEN:
            SetVentilatorState(0,air_quality_state);/* it is just possible to turn off the ventilation when the Air quality is good!*/
            setVentilatorBuzzer(air_quality_state);

            /*set next state*/
                for(i=0;i<4;i++) {
                air_quality_state=GetAirQualityState(i);

                if(air_quality_state == RED) {
                    tmp=air_quality_state;
                    break;
                }
                else if(air_quality_state == YELLOW) {
                    tmp=YELLOW;
                }
            }
            air_quality_state=tmp;
            break;

        case YELLOW:
            SetVentilatorState(0,air_quality_state);
            setVentilatorBuzzer(air_quality_state);

            /*set next state*/
            for(i=0;i<4;i++) {
                air_quality_state=GetAirQualityState(i);

                if(air_quality_state == RED) {
                    tmp=air_quality_state;
                    break;
                }
                else if(air_quality_state == YELLOW) {
                    tmp=YELLOW;
                }
            }
            air_quality_state=tmp;
            break;

        case RED:
            SetVentilatorState(0,air_quality_state);
            setVentilatorBuzzer(air_quality_state);
            
            /*set next state*/
            for(i=0;i<4;i++) {
                air_quality_state=GetAirQualityState(i);

                if(air_quality_state == RED) {
                    tmp=air_quality_state;
                    break;
                }
                else if(air_quality_state == YELLOW) {
                    tmp=YELLOW;
                }
            }
            air_quality_state=tmp;
            break;

        default:
            SetVentilatorState(0,GREEN);
            setVentilatorBuzzer(GREEN);
            /*SetWarning();something that declares that something went wrong*/
            break;
    }
}
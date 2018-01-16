#include "statemachine_airquality_control.h"

/**
 *      @brief  This function is used to test the testmachines -> a virtual register is placed to simulate turn ons of LED'S
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */

int main(int argc, char** argv)
{
    
    // Variable declarations;
    int i=0;
    ResetAirQualityState();
    /*first set temperature to 60 degree*/
    int length = 6;
    /* state before, setHeater state after*/
    int Result[3], Result_complete[length];
    /* set sensor values for test*/
    int sensor_values[5]={0.62,.62,.62,.62,.62};
    /*set thresholds*/
    /* set yellow thresholds */
    while(1){
        statemachine_air_quality(0,Result);
        int j;
        for(j=0;j<5;j++) {
        }
        printf("the state is: %d\n", get_air_quality_state(0));

    }
    return (EXIT_SUCCESS);
}


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
    double sensor_values[5]={0.62,.62,.62,.62,.62};
    SetAirQuality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    SetAirThreshold(0,0,0,0.2);
    SetAirThreshold(0,0,1,0.2);
    SetAirThreshold(0,0,2,0.2);
    SetAirThreshold(0,0,3,0.2);
    SetAirThreshold(0,0,4,0.2);
    /* set red thresholds*/
    SetAirThreshold(0,1,0,0.6);
    SetAirThreshold(0,1,1,0.6);
    SetAirThreshold(0,1,2,0.6);
    SetAirThreshold(0,1,3,0.6);
    SetAirThreshold(0,1,4,0.6);
    while(1){
        Statemachine_AirQuality(0,Result);
        int j;
        for(j=0;j<5;j++) {
            SetHysteresis(1,j,0.01);
        }
        printf("the state is: %d\n", GetAirQualityState(0));

    }
    return (EXIT_SUCCESS);
}


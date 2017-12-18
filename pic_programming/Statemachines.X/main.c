#include "statemachine_light_control.h"
#include "statemachine_airquality_control.h"
#include "statemachine_watertemp_control.h"

/**
 *      @brief  This function is used to test the testmachines -> a virtual register is placed to simulate turn ons of LED'S
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */

int main(int argc, char** argv) {
    
    // Variable declarations;
    int i=0;
    while(1) {
        /*water temperature control*/
        Statemachine_WaterControl();

        /*light control*/
        SetNewCycle(2, 30);
        Statemachine_LightControl(0);
        Statemachine_LightControl(1);
        Statemachine_LightControl(2);
        Statemachine_LightControl(3);

        /*Air Quality*/
        Statemachine_AirQuality(0);
        Statemachine_AirQuality(1);
        Statemachine_AirQuality(2);
        Statemachine_AirQuality(3);

        /*Airtemperature Control*/
        SetAirThreshold(2, 1, 0, 0.567);
        int k;
        for (k = 0; k < 4; k++) {
            Statemachine_AirControl(k);
        }
    }
    return (EXIT_SUCCESS);
}


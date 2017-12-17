#include "statemachine_light_control.h"
#include "statemachine_airquality_control.h"
#include "statemachine_watertemp_control.h"

/**
 *      @brief  This function will run alongside the clock hall
 *     @author  Samuel Simoes, samuelmsimoes@ua.pt
 *     Created  20-Set-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */

int main(int argc, char** argv) {
    
    // Variable declarations;
    int i=0;
        /*water temperature control*/
        Statemachine_WaterControl(60);
        
        /*light control*/
        Statemachine_LightControl(0);
        Statemachine_LightControl(1);
        Statemachine_LightControl(2);
        Statemachine_LightControl(3);
        
        /*Air Quality*/
        Statemachine_AirQuality();
        
        /*Airtemperature Control*/
        int k;
        for(k=0;k<4;k++){
            Statemachine_AirControl(k, 25);
        }

    return (EXIT_SUCCESS);
}


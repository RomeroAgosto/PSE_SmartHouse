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
#define TEST_SCHEDULE 0
#if TEST_SCHEDULE == 1
#include "schedules.h"
int init_schedule(){
    char to_send[100]="111112322002305";
    get_schedule_message(to_send);

}

#endif
int main(int argc, char** argv) {
    
    // Variable declarations;
    int i=0;
        //valuesinti();
        //init_schedule();
        /*water temperature control*/
        Statemachine_WaterControl();
        
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
            Statemachine_AirControl(k);
        }

    return (EXIT_SUCCESS);
}


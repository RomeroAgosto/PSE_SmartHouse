#include "statemachine_light_control.h"

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
    while(i<100){
        set_desired_light(0,1);
        set_light_sensor_values(0,1);
        int test[4];
        statemachine_light_control(0,test);
        printf("test[%d]=%d\n",1,test[1]);
        i++;
        }

    return (EXIT_SUCCESS);
}


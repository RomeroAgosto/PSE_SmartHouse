#include "statemachine_watertemp_control.h"

/**
 *      @brief  This function is used to test just the water_statemachine
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */

int main(int argc, char** argv) {
    
    // Variable declarations;
    int a[2];
    int i=0;
    while(1) {
        /*water temperature control*/
        statemachine_water_control(a);
    }
    return (EXIT_SUCCESS);
}


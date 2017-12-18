#include "statemachine_watertemp_control.h"
/**
 *      @brief  replace the desiredWaterTemperature
 *     Created  20-Set-2017
 *     Company  DeepImpact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
int desiredWaterTemperature_dummy(){
    return 50;
}

/**
 *      @brief  replace the SetWaterHeater function
 *      @param  Command turn On=TRUE, Turn off = FALSE
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  DeepImpact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
int SetWaterHeaterSate_dummy(int Command){
    if (Command==TRUE){printf("water turned on\n");}
    else {printf("water turned off \n");}
    return 1;
}
/**
 *      @brief  Setter Functions to adapt the thresholds -> Can be just used from the technician
 *      @param  room: for which room should the threshold be set
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  DeepImpact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
int GetWaterTemperature_dummy(){
    return 50; /* dummy which returns a temperature to check the behaviour of the state machine*/
}

/**
 *      @brief  Statemachine which controls the Water state
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  DeepImpact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
void Statemachine_WaterControl(){
#if _DEBUG == 0
    int water_temperature=GetWaterTemperature();
    int desired_temperature= desiredWaterTemperature();
#else
    int water_temperature=GetWaterTemperature_dummy();
    int desired_temperature= desiredWaterTemperature_dummy();
#endif
    upper_threshold_water=desired_temperature+5; /*trigger band is 10 degrees!*/
    lower_threshold_water=desired_temperature-5;
    /* states are stored in the states variables. so higher function can easily access the current states*/
    switch (water_temp_state) {

        case DESIRED_TEMPERATURE:
#if _DEBUG == 0
            SetWaterHeaterSate(FALSE);
#else
            SetWaterHeaterSate_dummy(FALSE);
#endif
            if (water_temperature<lower_threshold_water){water_temp_state=INCREASE_WATER_TEMPERATURE;} /*Implementation of Schmitt -Trigger misses here*/
            break;

        case INCREASE_WATER_TEMPERATURE:
#if _DEBUG == 0
            SetWaterHeaterSate(TRUE);
#else
            SetWaterHeaterSate_dummy(TRUE);
#endif

            if (water_temperature>upper_threshold_water){water_temp_state=DESIRED_TEMPERATURE;}
            break;
        default:
#if _DEBUG == 0
            SetWaterHeaterSate(FALSE);
#else
            SetWaterHeaterSate_dummy(FALSE);
#endif

            break;
    }
}
#include "statemachine_watertemp_control.h"
int water_threshold=5;
static int water_temp_state;
int upper_threshold_water=65; /*just to provide initial values*/
int lower_threshold_water=55;

int set_water_threshold(int threshold){
    water_threshold=threshold;
}

#if UNITTEST == 1
int desired_test;
int water_temp;
int heater_state;
#include <stdio.h>
int reset_state_water_temp(){
    water_temp_state=0;
}
int set_water_temp(int temp){
    water_temp=temp;
}
int GetWaterTemperature(){
    return water_temp;
}
int set_desired_temperature(int temp){
    desired_test=temp;
}
int desiredWaterTemperature(){
    return desired_test;
}
int SetWaterHeaterSate(int set){
    heater_state=set;
}

#endif

#if UNITTEST==1
    int Statemachine_WaterControl(int *test){
    test[0]=water_temp_state;

#else
    void Statemachine_WaterControl(){
#endif
    int water_temperature=GetWaterTemperature();
    int desired_temperature= desiredWaterTemperature();

    upper_threshold_water=desired_temperature+water_threshold;
    lower_threshold_water=desired_temperature-water_threshold;
    /* states are stored in the states variables. so higher function can easily access the current states*/
    switch (water_temp_state) {

        case DESIRED_TEMPERATURE:
            SetWaterHeaterSate(FALSE);
            if (water_temperature<lower_threshold_water){
                water_temp_state=INCREASE_WATER_TEMPERATURE;
            } /*Implementation of Schmitt -Trigger misses here*/
            break;

        case INCREASE_WATER_TEMPERATURE:
            SetWaterHeaterSate(TRUE);

            if (water_temperature>upper_threshold_water){water_temp_state=DESIRED_TEMPERATURE;}
            break;
        default:
            SetWaterHeaterSate(FALSE);

            break;
    }
#if UNITTEST == 1
        test[1]=heater_state;
        test[2]=water_temp_state;
#endif
}
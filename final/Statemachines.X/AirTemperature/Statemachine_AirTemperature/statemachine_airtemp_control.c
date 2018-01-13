#include "statemachine_airtemp_control.h"

static int desired_temp[8]; /*!< the desired_temp will be updated by the global sensor structure -> getter function, every room_inserted has its own temp*/
static int air_temp_state[8]={0};/*!< stored the temp_state from all room_inserteds */
/**
 *      @brief  Dummy function to receive the desired Air Temperature
 *      @param  room_inserted
 *      @return Sensorvalue in degree -> just integer
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
#if UNITTEST == 1
int heating_state;
int air_temperature[8]={0};
int air_temperature_hysteresis=1;

int set_air_temp_hysteresis(int room, int hysteresis){
    air_temperature_hysteresis=hysteresis;
}
int get_air_temp_hysteresis(int room){
    return air_temperature_hysteresis;
}

void reset_state_air_temp(room_inserted ){
    air_temp_state[room_inserted]=0;
}

int SetHeater(int room_inserted,int abc){
    return 0;
}

/************** desired temperature *///////////////////
int setdesiredTemp(int room_inserted,int temp){
    desired_temp[room_inserted]=temp;
}
int desiredAirTemperature(int room_inserted){
    return desired_temp[room_inserted];
}
/**
 *      @brief  Dummy function to set heat ventilation
 *      @param  heater on = TRUE, off = FALSE
 *      @return Sensorvalue in degree -> just integer
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */

int SetHeatingAirState(int room_inserted, int on){
    heating_state=on;
    return 1; /*we should introduce a check, if this procedure was successful */
}

/**
 *      @brief  Function to emulate the gobal sensor struct
 *      @input  The input is simply the room_inserted number
 *      @return Sensorvalue in degree -> just integer
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */


int SetAirTemperature(int room_inserted, int temp){
    air_temperature[room_inserted ]=temp;
    return 0;
}
int GetAirTemperature(int room_inserted){
    return air_temperature[room_inserted]; /* dummy which returns a temperature to check the behaviour of the state machine*/
}

/**
 *      @brief  This state machine implements the air temperature control: all decison regarding the heating is made here
 *      @input  The input is simply the room_inserted number
 *      @states The states used to describe the behavior are the DESIRED TEMPERATURE and INCREASE TEMPERATURE 
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
void Statemachine_AirControl(int room_inserted,int *test) {
    test[0]=air_temp_state[room_inserted];

#else
void Statemachine_AirControl(int room_inserted){
#endif
    desired_temp[room_inserted]=desiredAirTemperature(room_inserted);
    int air_temperature=GetAirTemperature(room_inserted); /*!< in air_temperature are the current values saved -> getter function from the global struct */
    //printf("desired_temp[%d] = %d\n temp is: %d \n",room_inserted,desired_temp[room_inserted],air_temperature);
    lower_threshold_air=desired_temp[room_inserted]-get_air_temp_hysteresis(room_inserted); /*!< the lower_threshold_air is the lower band of the trigger in order to avoid shuttering*/
    upper_threshold_air=desired_temp[room_inserted]+get_air_temp_hysteresis(room_inserted);/*!< the upper_threshold_air is the upper band of the trigger in order to avoid shuttering*/
    switch (air_temp_state[room_inserted]) {

        case DESIRED_TEMPERATURE:
            SetHeatingAirState(room_inserted,FALSE);
            SetHeater(room_inserted,FALSE);
            /*set next state*/
            if (air_temperature<lower_threshold_air){air_temp_state[room_inserted]=INCREASE_AIR_TEMPERATURE;} /*If the values drops below the lower threshold increase! -> Avoid shutter*/
            break;

        case INCREASE_AIR_TEMPERATURE:
            SetHeatingAirState(room_inserted,TRUE);
            SetHeater(room_inserted,TRUE);
            /*set next state*/
            if(air_temperature>lower_threshold_air){air_temp_state[room_inserted]=DESIRED_TEMPERATURE;} /* If the value exceeds the threshold, turn off -> avoid shutter*/
            break;

        default:
            SetHeatingAirState(room_inserted,0);
            /*SetWarning();something that declares that something went wrong*/
            break;
    }
   // printf("air temp state[1] %d\n",air_temp_state[1]);
#if UNITTEST == 1
    test[1]=heating_state;
    test[2]=air_temp_state[room_inserted];

#endif

}

#include "statemachine_airtemp_control.h"

static int desired_temp[8]; /*!< the desired_temp will be updated by the global sensor structure -> getter function, every room has its own temp*/
static int air_temp_state[8]={0};/*!< stored the temp_state from all rooms */

/**
 *      @brief  Dummy function to receive the desired Air Temperature
 *      @param  room
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

void reset_state_air_tempnt room ){
    air_temp_state[room]=0;
}

/************** desired temperature *///////////////////
int setdesiredTemp(int room,int temp){
    desired_temp[room]=temp;
}
int desiredAirTemperature(int room){
    return desired_temp[room];
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

int SetHeatingAirState(int room, int on){
    heating_state=on;
    return 1; /*we should introduce a check, if this procedure was successful */
}

/**
 *      @brief  Function to emulate the gobal sensor struct
 *      @input  The input is simply the room number
 *      @return Sensorvalue in degree -> just integer
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */

int SetAirTemperature(int room, int temp){
    air_temperature[room ]=temp;
    return 0;
}
int GetAirTemperature(int room){
    return air_temperature[room]; /* dummy which returns a temperature to check the behaviour of the state machine*/
}

/**
 *      @brief  This state machine implements the air temperature control: all decison regarding the heating is made here
 *      @input  The input is simply the room number
 *      @states The states used to describe the behavior are the DESIRED TEMPERATURE and INCREASE TEMPERATURE 
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
void Statemachine_AirControl(int room,int *test) {
    test[0]=air_temp_state[room];

#else
void Statemachine_AirControl(int room);
#endif

    desired_temp[room]=desiredAirTemperature(room);
    int air_temperature=GetAirTemperature(room); /*!< in air_temperature are the current values saved -> getter function from the global struct */
    //printf("desired_temp = %d\n temp is: %d \n",desired_temp[room],air_temperature);
    lower_threshold_air=desired_temp[room]-1; /*!< the lower_threshold_air is the lower band of the trigger in order to avoid shuttering*/
    upper_threshold_air=desired_temp[room]+1;/*!< the upper_threshold_air is the upper band of the trigger in order to avoid shuttering*/

    switch (air_temp_state[room]) {

        case DESIRED_TEMPERATURE:
            SetHeatingAirState(room,0);
            /*set next state*/
            if (air_temperature<lower_threshold_air){air_temp_state[room]=INCREASE_AIR_TEMPERATURE;} /*If the values drops below the lower threshold increase! -> Avoid shutter*/
            break;

        case INCREASE_AIR_TEMPERATURE:
            SetHeatingAirState(room,1);

            /*set next state*/
            if(air_temperature>lower_threshold_air){air_temp_state[room]=DESIRED_TEMPERATURE;} /* If the value exceeds the threshold, turn off -> avoid shutter*/
            break;

        default:
            SetHeatingAirState(room,0);
            /*SetWarning();something that declares that something went wrong*/
            break;
    }
   // printf("air temp state[1] %d\n",air_temp_state[1]);
#if UNITTEST == 1
    test[1]=heating_state;
    test[2]=air_temp_state[room];

#endif

}

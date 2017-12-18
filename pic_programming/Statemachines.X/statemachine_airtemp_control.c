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

int desiredAirTemperatureDummy(int room){
    return 25;
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
int SetHeatingAirDummy(int room, int on){
    printf("heater of room %d is turned: %d\n",room,on);
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
int GetAirTemperatureDummy(int room){
    return 20; /* dummy which returns a temperature to check the behaviour of the state machine*/
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
void Statemachine_AirControl(int room) {


#if _DEBUG==0
    desired_temp[room]=desiredAirTemperature(room);
    int air_temperature=GetAirTemperature(room); /*!< in air_temperature are the current values saved -> getter function from the global struct */
#else
    desired_temp[room]=desiredAirTemperatureDummy(room);/*the desired_temp will asked from the global structure*/
    int air_temperature=GetAirTemperatureDummy(room); /*!< in air_temperature are the current values saved -> getter function from the global struct */
#endif
    lower_threshold_air=desired_temp[room]-1; /*!< the lower_threshold_air is the lower band of the trigger in order to avoid shuttering*/
    upper_threshold_air=desired_temp[room]+1;/*!< the upper_threshold_air is the upper band of the trigger in order to avoid shuttering*/

    switch (air_temp_state[room]) {

        case DESIRED_TEMPERATURE:
#if _DEBUG==0
            SetHeatingAirState(room,FALSE);
#else
            SetHeatingAirDummy(room,FALSE);/*uses the set function of the sensor structure*/
#endif
            /*set next state*/
            if (air_temperature<lower_threshold_air){air_temp_state[room]=INCREASE_AIR_TEMPERATURE;} /*If the values drops below the lower threshold increase! -> Avoid shutter*/
            break;

        case INCREASE_AIR_TEMPERATURE:
#if _DEBUG==0
            SetHeatingAirState(TRUE);
#else
            SetHeatingAirDummy(room,TRUE);
#endif
            /*set next state*/
            if(air_temperature>lower_threshold_air){air_temp_state[room]=DESIRED_TEMPERATURE;} /* If the value exceeds the threshold, turn off -> avoid shutter*/
            break;

        default:
#if _DEBUG==0
            SetHeatingAirState(FALSE);
#else
            SetHeatingAirDummy(room,FALSE);
#endif
            /*SetWarning();something that declares that something went wrong*/
            break;
    }

}

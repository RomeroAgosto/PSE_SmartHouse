#include "statemachine_airquality_control.h"
#include <string.h>

static int thresholds[4][2][5];  /*!< Thresholds for the specific air quality parameter -> can be adapted by a setter function*/
static int air_quality_state=0; /*!< statemachine states are in general protected and just inside of the function known */

/**
 *      @brief  Setter Functions to adapt the thresholds -> Can be just used from the technician
 *      @param  room: for which room should the threshold be set
 *      @param  Choose if upper or lower threshold: 0 lower, 1: upper
 *      @param  threshold: choose the Threshold parameter 0: p10, 1: co, 2: co2, 3: o3, 4: humidity
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  DeepImpact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
int SetAirThreshold(int room,int warning_level, int threshold, double value){
    printf("threshold %d of warining level %d of room %d was  set to %f",threshold,warning_level,room,value);
        thresholds[room][warning_level][threshold]=value;
};

/**
 *      @brief  Dummy function for setting the color
 *      @param  color: which color should be used? 
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  DeepImpact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
int SetLightQuality_dummy(int room,int  color){
    printf("Color output of room %d is: %d\n", room,color);
};
/**
 *      @brief Since the state is protected inside of the function, other functions can get the state thorugh this function
 *      @return returns the current state of the air quality control -> RED/YELLOW/GREEN
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
int GetAirQualityState(){
    return air_quality_state;
}
/**
 *      @brief Function to check the air quality_statemachine -> this function can provide artificial Temp values
 *      @param room: sensors for which room?
 *      @param sensor_values: pointer to the sensor value array as provided by the sensor struct
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */

int GetAirQuality_dummy(int room, double *sensor_values){
    sensor_values[0]=0.1;
    sensor_values[1]=0.2;
    sensor_values[2]=0.1;
    sensor_values[3]=0.2;
    sensor_values[4]=0.1;
    return 1;
}

/**
 *      @brief  Function sets a alarm, connect to a pin, here a dummy pin
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */

int SetWarning(){
    printf("dummy for message warning");
}
/**
 *      @brief  function simulates a Ventilation turn on
 *      @param  on
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */

int SetVentilationState_dummy(int room,int on){
    printf("set ventlation %d",on);
}
/**
 *      @brief  This state machine implements the air quality control, inside of this function, the decisions are made
 *      @states The states used to describe the behavior are RED GREEN and YELLOW and they represent the current air quality
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */


void Statemachine_AirQuality(int room) {
	double sensor_values[5]; /*!< the getter function will return an array pointer with all defined values */
    int air_quality;
    static int air_quality_state[4];
#if _DEBUG ==0
    GetAirQuality(room,sensor_values); /*!< in air_quality the current value will be saved -> getter function from the global struct */
#else
    GetAirQuality_dummy(room, sensor_values);
#endif
    int j;
    /* check Yellow first, RED can overwrite YELLOW -> when one Value exceeds the preset limit -> react*/
    for (j = 0; j <5 ; j++) {
        if (sensor_values[j] > thresholds[room][0][j]){air_quality=YELLOW;};
    }
    for (j = 0; j <5 ; j++) {
        if (sensor_values[j] > thresholds[room][1][j]){air_quality=RED;};
    }
    /* states are stored in the states variables. so higher function can easily access the current states*/
    switch (air_quality_state[room]) {

        case GREEN:
#if _DEBUG==0
            SetLightQuality(room,GREEN);
            SetVentilationState(room,FALSE);/* it is just possible to turn off the ventilation when the Air quality is good!*/
#else
            SetLightQuality_dummy(room,GREEN);
            SetVentilationState_dummy(room,FALSE);/* it is just possible to turn off the ventilation when the Air quality is good!*/
#endif

            /*It is double check, but thus im not gonna break the state machine principle is used*/
            if (air_quality==RED){air_quality_state[room]=RED;}
            else if(air_quality==YELLOW){air_quality_state[room]=YELLOW;}
            break;

        case YELLOW:
#if _DEBUG==0
            SetLightQuality(room,YELLOW);
            SetVentilationState(room,FALSE);/* it is just possible to turn off the ventilation when the Air quality is good!*/
#else
            SetLightQuality_dummy(room,YELLOW);
            SetVentilationState_dummy(room,TRUE);/* it is just possible to turn off the ventilation when the Air quality is good!*/
#endif
            /*It is double check, but thus im not gonna break the state machine principle is used*/
            if (air_quality==RED){air_quality_state[room]=RED;}
            else if(air_quality==YELLOW){air_quality_state[room]=YELLOW;}
            break;

        case RED:
#if _DEBUG==0
            SetLightQuality(RED);
            SetVentilationState(TRUE);/* it is just possible to turn off the ventilation when the Air quality is good!*/
#else
            SetLightQuality_dummy(room,RED);
            SetVentilationState_dummy(room,TRUE);/* it is just possible to turn off the ventilation when the Air quality is good!*/
#endif
            /*set next state*/
            /*It is double check, but thus im not gonna break the state machine principle is used*/
            if (air_quality==RED){air_quality_state[room]=RED;}
            else if(air_quality==YELLOW){air_quality_state[room]=YELLOW;}
            SetWarning();/*something that declares that something went wrong*/
            break;

        default:
#if _DEBUG==0
            SetLightQuality(room,RED);
            SetVentilationState(room,TRUE);
#else
            SetLightQuality_dummy(room,FALSE);
            SetVentilationState_dummy(room,TRUE);
#endif
            SetWarning();/*something that declares that something went wrong*/
            break;
    }
}

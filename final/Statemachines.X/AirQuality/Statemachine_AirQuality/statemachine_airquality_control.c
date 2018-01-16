#include "statemachine_airquality_control.h"
static int air_quality_state[4];/*!< statemachine states are in general protected and just inside of the function known */


/**
 *      @brief Since the state is protected inside of the function, other functions can get the state thorugh this function
 *      @return returns the current state of the air quality control -> RED/YELLOW/GREEN
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
int get_air_quality_state(int room){
    return air_quality_state[room];
}


/**
 *      @brief  Function sets a alarm, connect to a pin, here a dummy pin
 *     Created  20-Set-2017
 *     Company  Deep Impact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */

int set_warning(){
    //printf("dummy for message warning");
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

#if UNITTEST == 1
static int sensor_values_test[4][5];
static int thresholds[2][5]={{20,600,25,100,2},{65,5000,200,200,100}};  /*!< Thresholds for the specific air quality parameter -> can be adapted by a setter function*/

static int bounds_sensorvalues[2][5]={{2, 20, 2,5,1},{2, 20, 2, 2,2}};/*!<Hysteresis for the air quality [2] indicates the stage (red yellow), [5] indicates the sensorvalue*/



int set_air_quality_hysteresis(int risk_level,int sensor, int value){
    bounds_sensorvalues[risk_level][sensor]=value;
    //printf("set air bound %d of sensor %d to %d\n",risk_level,sensor,value);
}
int get_air_quality_hysteresis(int risk_level,int sensor){
    return bounds_sensorvalues[risk_level][sensor];
}

int set_air_quality_threshold(int risk_level, int threshold, int value){
    thresholds[risk_level][threshold]=value;
}
int get_air_quality_threshold(int risk_level, int threshold){
    return thresholds[risk_level][threshold];
}
/********** AirQualitySensors ********************/
void set_air_quality(int room, int *input_values){
    sensor_values_test[room][0]=input_values[0];
    sensor_values_test[room][1]=input_values[1];
    sensor_values_test[room][2]=input_values[2];
    sensor_values_test[room][3]=input_values[3];
    sensor_values_test[room][4]=input_values[4];
    //printf("sensor values are: %d %d %d %d %d\n",sensor_values_test[room][0],sensor_values_test[room][1],sensor_values_test[room][2],sensor_values_test[room][3],sensor_values_test[room][4]);
}
void get_air_quality(int room, int *sensor_values){
    sensor_values[0]=sensor_values_test[room][0];
    sensor_values[1]=sensor_values_test[room][1];
    sensor_values[2]=sensor_values_test[room][2];
    sensor_values[3]=sensor_values_test[room][3];
    sensor_values[4]=sensor_values_test[room][4];
    //printf("im returning %d %d %d %d %d\n",sensor_values[0],sensor_values[1],sensor_values[2],sensor_values[3],sensor_values[4]);
}

/********** SetLightQuality **********************/
static int room_color;
void set_ventilator_buzzer( int color){
    room_color=color;
}
/********** SetVentilation State**********/
static int Ventilation_state [4];
void set_ventilator_state(int room, int on){
    Ventilation_state[room]=on;
}
/******** reset ventilation state *******/
void reset_air_quality_state(){
    air_quality_state[0]=0;
    air_quality_state[1]=0;
    air_quality_state[2]=0;
    air_quality_state[3]=0;
}


void statemachine_air_quality(int room,int *test) {
    test[0]=air_quality_state[room];
#else
void statemachine_air_quality(int room) {
#endif
	int sensor_values[5]; /*!< the getter function will return an array pointer with all defined values */
    int air_quality;
    get_air_quality(room,sensor_values); /*!< in air_quality the current value will be saved -> getter function from the global struct */

    int j,green_count=0,yellow_count=0;

    /* states are stored in the states variables. so higher function can easily access the current states*/
    switch (air_quality_state[room]) {
        case GREEN:
            set_ventilator_buzzer(GREEN);
            set_ventilator_state(room,FALSE);/* it is just possible to turn off the ventilation when the Air quality is good!*/
            /* check Yellow first, RED can overwrite YELLOW -> when one Value exceeds the preset limit -> react*/
            for (j = 0; j <5 ; j++) {
                if (sensor_values[j] > get_air_quality_threshold(0,j)+get_air_quality_hysteresis(0,j)){air_quality_state[room]=YELLOW;}
            }
            for (j = 0; j <5 ; j++) {
                if (sensor_values[j] > get_air_quality_threshold(1,j) +get_air_quality_hysteresis(1,j)) {
                    air_quality_state[room] = RED;}
            }
            break;

        case YELLOW:
            set_ventilator_buzzer(YELLOW);
            set_ventilator_state(room,TRUE);
            for (j = 0; j <5 ; j++) {
               // printf("sensorvalue: %d threshold + bound %d\n",sensor_values[j],get_air_quality_threshold(room,0,j)-get_air_quality_hysteresis(0,j));

                if (sensor_values[j] < get_air_quality_threshold(0,j)-get_air_quality_hysteresis(0,j)){green_count++;}
            }
                        if(green_count==5) {air_quality_state[room]=GREEN;}
            
            for (j = 0; j <5 ; j++) {

                if (sensor_values[j] > (get_air_quality_threshold(1,j) + get_air_quality_hysteresis(1,j)) ){
                    air_quality_state[room] = RED;};
            }
            break;

        case RED:
            set_ventilator_buzzer(RED);
            set_ventilator_state(room, TRUE);/* it is just possible to turn off the ventilation when the Air quality is good!*/
            set_warning();/*something that declares that something went wrong*/
            /* Green overwrites Yellow -> first check if yellow condition fullfilled, if even a Green is, change to Green */
            for (j = 0; j <5 ; j++) {
                if (sensor_values[j] < get_air_quality_threshold(1,j) - get_air_quality_hysteresis(1,j)) {yellow_count++;}
            }
            if(yellow_count==5){air_quality_state[room]=YELLOW;}
            for (j = 0; j <5 ; j++) {
                if (sensor_values[j] < get_air_quality_threshold(0,j)-get_air_quality_hysteresis(0,j)){green_count++;};
            }
            if(green_count==5){air_quality_state[room]=GREEN;}
            break;

        default:
            set_ventilator_buzzer(RED);
            set_ventilator_state(room,TRUE);

            set_warning();/*something that declares that something went wrong*/
            break;
    }
#if UNITTEST == 1
    test[1]=Ventilation_state[room];
    test[2]=room_color;
    test[3]=air_quality_state[room];
    //printf("air_quality_state[%d] = %d, test[3] = %d\n",room,air_quality_state[room],test[3]);
#endif
}

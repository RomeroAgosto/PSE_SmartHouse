//
// Created by sascha on 14-12-2017.
//

#ifndef LOG_SEND_LOG_STRU_H
#define LOG_SEND_LOG_STRU_H

/** \file log_functions.h
* \brief functions that allow log management
* \author Rafael Almeida
*
* \date 15-12-2017
*/


/** 
* \brief this function saves the sensor information and saves it
 * \author Rafael Almeida 
* \date 14-12-2017  
*/

int log_data_saving();


/** 
* \brief This functions creates a message with all the information present in the log
* \param  message receve the pointer to put a string
 * \author Rafael Almeida 
* \date 03-11-2017  
*/

int log_create_msg(char *message);

typedef union{
    struct{
        int time_y;
        int time_mo;
        int time_h;
        int time_min;
        int time_s;
        int air_temp_0;
        int air_temp_1;
        int air_temp_2;
        int air_temp_3;
        int air_temp_4;
        int air_temp_5;
        int air_temp_6;
        int air_temp_7;
        int air_status_0;
        int air_status_1;
        int air_status_2;
        int air_status_3;
        int air_status_4;
        int air_status_5;
        int air_status_6;
        int air_status_7;
        int water_temp;
        int water_state;
        int air_quality_0;
        int air_quality_1;
        int air_quality_2;
        int air_quality_3;

    };  int sensor_data[27];
} measured_data;
typedef union{
    struct{
        measured_data measurement_0;
        measured_data measurement_1;
        measured_data measurement_2;
        measured_data measurement_3;
        measured_data measurement_4;
        measured_data measurement_5;
        measured_data measurement_6;
        measured_data measurement_7;
        measured_data measurement_8;
        measured_data measurement_9;
        measured_data measurement_10;
        measured_data measurement_11;
        measured_data measurement_12;
        measured_data measurement_13;
        measured_data measurement_14;
        measured_data measurement_15;
        measured_data measurement_16;
        measured_data measurement_17;
        measured_data measurement_18;
        measured_data measurement_19;
        measured_data measurement_20;
        measured_data measurement_21;
        measured_data measurement_22;
        measured_data measurement_23;
        measured_data measurement_24;
        measured_data measurement_25;
        measured_data measurement_26;
        measured_data measurement_27;
        measured_data measurement_28;
        measured_data measurement_29;
        measured_data measurement_30;
        measured_data measurement_31;
        measured_data measurement_32;
        measured_data measurement_33;
        measured_data measurement_34;
        measured_data measurement_35;
        measured_data measurement_36;
        measured_data measurement_37;
        measured_data measurement_38;
        measured_data measurement_39;
        measured_data measurement_40;
        measured_data measurement_41;
        measured_data measurement_42;
        measured_data measurement_43;
        measured_data measurement_44;
        measured_data measurement_45;
        measured_data measurement_46;
        measured_data measurement_47;

    }; measured_data data[48];
} log;

#endif //LOG_SEND_LOG_STRU_H

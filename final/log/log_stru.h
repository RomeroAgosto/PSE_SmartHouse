//
// Created by sascha on 14-12-2017.
//

#ifndef LOG_SEND_LOG_STRU_H
#define LOG_SEND_LOG_STRU_H

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
} log[48];


#endif //LOG_SEND_LOG_STRU_H

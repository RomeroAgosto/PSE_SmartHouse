#include "technician_structure.h"
#include <stdio.h>

technician technician_settings;

int message_counter_technician=2;

int set_new_thresholds(char *message,int p) {
    int j,k,i=0;
    printf("p is %d\n",p);
    printf("%s\n",message);
    message_counter_technician=p+2;
    for (i = 0; i < 2; i++) {
        for(j = 0;j < 5; j++) {
            set_air_quality_hysteresis(i,j,(message[message_counter_technician] - '0') * 10 + message[message_counter_technician+1] - '0'); /*hysteresis air quality*/

        }
    }

    for (j = 0; j < 2; j++) {
         for(k=0;k<5;k++) {
             printf("threshold %d\n ",(message[ message_counter_technician] - '0') * 1000 + (message[message_counter_technician+1] - '0') * 100 + (message[message_counter_technician +2 ] - '0')*10 + message[message_counter_technician +3 ] - '0');
             set_air_quality_threshold(j,k,(message[ message_counter_technician] - '0') * 1000 + (message[message_counter_technician+1] - '0') * 100 + (message[message_counter_technician +2 ] - '0')*10 + message[message_counter_technician +3 ] - '0');

         }
    }

    for(i=0;i<8;i++) {
        printf("air_temp_hysteresis %d\n\r ",message[message_counter_technician]-'0');
        set_air_temp_hysteresis(i,message[message_counter_technician]-'0');
    }
    printf("water_temp_hysteresis %d\n\r ",message[message_counter_technician]-'0');
    set_water_hysteresis(message[message_counter_technician]-'0');
    for (i = 0;i  < 4; i++) {
        printf("light cycle %d\n\r ",(message[message_counter_technician]-'0')*10+message[message_counter_technician+1]-'0');
        set_light_cycles(i,(message[message_counter_technician]-'0')*10+(message[message_counter_technician+1]-'0'));
    }
}
int set_light_cycles(int light_number, int cycle_time){
    message_counter_technician=message_counter_technician+2;
    technician_settings.cycles_light[light_number]=cycle_time;
}
int get_light_cycles(int light_number){
    return technician_settings.cycles_light[light_number];
}

int set_air_temp_hysteresis(int room, int hysteresis){
    message_counter_technician++;
    technician_settings.hysteresis_air_temp[room]=hysteresis;
}
int get_air_temp_hysteresis(int room){
    return technician_settings.hysteresis_air_temp[room];
}

int set_air_quality_hysteresis(int risk_level,int sensor, int value){
    technician_settings.hysteresis_air_quality[risk_level][sensor]=value;
    message_counter_technician=message_counter_technician+2;

}
int get_air_quality_hysteresis(int risk_level,int sensor){
    return technician_settings.hysteresis_air_quality[risk_level][sensor];
}

int set_air_quality_threshold(int risk_level, int threshold, int value){
    technician_settings.threshold_air_quality[risk_level][threshold]=value;
    message_counter_technician=message_counter_technician+4;
}
int get_air_quality_threshold(int risk_level, int threshold){
    return technician_settings.threshold_air_quality[risk_level][threshold];
}

int set_water_hysteresis(int hysteresis){
    technician_settings.hysteresis_water_temp=hysteresis;
    message_counter_technician++;
}

int get_water_hysteresis(){
    return technician_settings.hysteresis_water_temp;
}
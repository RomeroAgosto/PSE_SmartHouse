#include "technician_structure.h"

technician technician1;
int water_threshold=3;

int set_light_cycles(int light_number, int cycle_time){
    technician1.settings.cycles_light[light_number]=cycle_time;
}
int get_light_cycles(int light_number){
    return technician1.settings.cycles_light[light_number];
}

int set_air_temp_hysteresis(int room, int hysteresis){
    technician1.settings.hysteresis_air_temp[room]=hysteresis;
}
int get_air_temp_hysteresis(int room){
    return technician1.settings.hysteresis_air_temp[room];
}

int set_air_quality_hysteresis(int risk_level,int sensor, int value){
    technician1.settings.hysteresis_air_quality[risk_level][sensor]=value;
}
int get_air_quality_hysteresis(int risk_level,int sensor){
    return technician1.settings.hysteresis_air_quality[risk_level][sensor];
}

int set_air_quality_threshold(int room,int risk_level, int threshold, int value){
    technician1.settings.threshold_air_quality[room][risk_level][threshold]=value;
}
int get_air_quality_threshold(int room,int risk_level, int threshold){
    return technician1.settings.threshold_air_quality[room][risk_level][threshold];
}

int set_water_hysteresis(int hysteresis){
    water_threshold=technician1.settings.hysteresis_water_temp=hysteresis;
}

int get_water_hysteresis(){
    return water_threshold=technician1.settings.hysteresis_water_temp;
}
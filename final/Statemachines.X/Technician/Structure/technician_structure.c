#include "technician_structure.h"

technician technician1;
int water_threshold=3;
int set_new_thresholds(char *message) {
    int i=0;
    technician1.settings.hysteresis_air_quality[0][0]=message[2]-'0'; /*hysteresis air quality*/
    technician1.settings.hysteresis_air_quality[0][1]=message[3]-'0'-'0';
    technician1.settings.hysteresis_air_quality[0][2]=message[4]-'0';
    technician1.settings.hysteresis_air_quality[0][3]=message[5]-'0';
    technician1.settings.hysteresis_air_quality[0][4]=message[6]-'0';
    technician1.settings.hysteresis_air_quality[1][0]=message[7]-'0';
    technician1.settings.hysteresis_air_quality[1][1]=message[8]-'0';
    technician1.settings.hysteresis_air_quality[1][2]=message[9]-'0';
    technician1.settings.hysteresis_air_quality[1][3]=message[10]-'0';
    technician1.settings.hysteresis_air_quality[1][4]=message[11]-'0';

    technician1.settings.threshold_air_quality[0][0][0]=message[12]-'0';
    technician1.settings.threshold_air_quality[0][0][1]=message[13]-'0';
    technician1.settings.threshold_air_quality[0][0][2]=message[14]-'0';
    technician1.settings.threshold_air_quality[0][0][3]=message[15]-'0';
    technician1.settings.threshold_air_quality[0][0][4]=message[16]-'0';
    technician1.settings.threshold_air_quality[0][1][0]=message[17]-'0';
    technician1.settings.threshold_air_quality[0][1][1]=message[18]-'0';
    technician1.settings.threshold_air_quality[0][1][2]=message[19]-'0';
    technician1.settings.threshold_air_quality[0][1][3]=message[20]-'0';
    technician1.settings.threshold_air_quality[0][1][4]=message[21]-'0';

    technician1.settings.threshold_air_quality[1][0][0]=message[22]-'0';
    technician1.settings.threshold_air_quality[1][0][1]=message[23]-'0';
    technician1.settings.threshold_air_quality[1][0][2]=message[24]-'0';
    technician1.settings.threshold_air_quality[1][0][3]=message[25]-'0';
    technician1.settings.threshold_air_quality[1][0][4]=message[26]-'0';
    technician1.settings.threshold_air_quality[1][1][0]=message[27]-'0';
    technician1.settings.threshold_air_quality[1][1][1]=message[28]-'0';
    technician1.settings.threshold_air_quality[1][1][2]=message[29]-'0';
    technician1.settings.threshold_air_quality[1][1][3]=message[30]-'0';
    technician1.settings.threshold_air_quality[1][1][4]=message[31]-'0';

    technician1.settings.threshold_air_quality[2][0][0]=message[32]-'0';
    technician1.settings.threshold_air_quality[2][0][1]=message[33]-'0';
    technician1.settings.threshold_air_quality[2][0][2]=message[34]-'0';
    technician1.settings.threshold_air_quality[2][0][3]=message[35]-'0';
    technician1.settings.threshold_air_quality[2][0][4]=message[36]-'0';
    technician1.settings.threshold_air_quality[2][1][0]=message[37]-'0';
    technician1.settings.threshold_air_quality[2][1][1]=message[38]-'0';
    technician1.settings.threshold_air_quality[2][1][2]=message[39]-'0';
    technician1.settings.threshold_air_quality[2][1][3]=message[40]-'0';
    technician1.settings.threshold_air_quality[2][1][4]=message[41]-'0';

    technician1.settings.threshold_air_quality[3][0][0]=message[42]-'0';
    technician1.settings.threshold_air_quality[3][0][1]=message[43]-'0';
    technician1.settings.threshold_air_quality[3][0][2]=message[44]-'0';
    technician1.settings.threshold_air_quality[3][0][3]=message[45]-'0';
    technician1.settings.threshold_air_quality[3][0][4]=message[46]-'0';
    technician1.settings.threshold_air_quality[3][1][0]=message[47]-'0';
    technician1.settings.threshold_air_quality[3][1][1]=message[48]-'0';
    technician1.settings.threshold_air_quality[3][1][2]=message[49]-'0';
    technician1.settings.threshold_air_quality[3][1][3]=message[50]-'0';
    technician1.settings.threshold_air_quality[3][1][4]=message[51]-'0';
    for(i=0;i<8;i++) {
        technician1.settings.hysteresis_air_temp[0] = message[52+i]-'0';
    }
    technician1.settings.hysteresis_water_temp=message[60]-'0';
    for (i = 0;i  < 4; i++) {
        technician1.settings.cycles_light[i] = message[60 + i]-'0';
    }
}
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
//
// Created by sascha on 12-01-2018.
//

#ifndef STATEMACHINES_X_TECHNICIAN_STRUCTURE_H
#define STATEMACHINES_X_TECHNICIAN_STRUCTURE_H

typedef union {
    struct {
        int threshold_air_quality[4][2][5];
        int hysteresis_air_quality[2][5];
        int hysteresis_air_temp[8];
        int hysteresis_water_temp;
        int cycles_light[4];
    }settings;
}technician;

int set_new_thresholds(char *message);

int set_light_cycles(int light_number, int cycle_time);
int get_light_cycles(int light_number);

int set_air_temp_hysteresis(int room, int hysteresis);
int get_air_temp_hysteresis(int room);

int set_air_quality_hysteresis(int risk_level,int sensor, int value);
int get_air_quality_hysteresis(int risk_level,int sensor);

int set_air_quality_threshold(int room,int risk_level, int threshold, int value);
int get_air_quality_threshold(int room,int risk_level, int threshold);

int set_water_hysteresis(int limit);
int get_water_hysteresis(void);

#endif //STATEMACHINES_X_TECHNICIAN_STRUCTURE_H

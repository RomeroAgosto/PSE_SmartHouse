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


int set_water_bound(int limit);
int get_water_bound();

#endif //STATEMACHINES_X_TECHNICIAN_STRUCTURE_H

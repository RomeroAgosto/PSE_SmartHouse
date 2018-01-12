#include "technician_structure.h"

technician technician1;
int water_threshold=3;

int set_water_hysteresis(int hysteresis){
    water_threshold=technician1.settings.hysteresis_water_temp=hysteresis;
}
int get_water_threshold(){
    return water_threshold=technician1.settings.hysteresis_water_temp;
}
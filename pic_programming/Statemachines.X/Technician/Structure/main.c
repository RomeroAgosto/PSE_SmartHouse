#include "technician_structure.h"
#include <stdio.h>

int main() {
    
    set_water_hysteresis(2);
    int bound = get_water_hysteresis();
    printf("%d bound \n",bound);

    set_air_quality_threshold(0,1,3,50);
    bound = get_air_quality_threshold(0,1,3);
    printf("%d bound \n",bound);

    set_air_quality_hysteresis(0,2,100);
    bound= get_air_quality_hysteresis(0,2);
    printf("%d bound \n",bound);

    set_air_temp_hysteresis(3,1);
    bound= get_air_temp_hysteresis(3);
    printf("%d bound \n",bound);

    set_light_cycles(3,40);
    bound=get_light_cycles(3);
    printf("%d bound \n",bound);
}


#include "technician_structure.h"
#include <stdio.h>

int main() {

    char message[]="#~02200205010220020202002006000025010000500065500002000200010012345678120212223*";
    set_new_thresholds(message,2);

    int bound = get_water_hysteresis();
    printf("%d water \n",bound);

    bound = get_air_quality_threshold(1,3);
    printf("%d air_quality_threshold \n",bound);

    bound= get_air_quality_hysteresis(0,2);
    printf("%d air quality_hysteresis \n",bound);

    bound= get_air_temp_hysteresis(3);
    printf("%d air_temp \n",bound);

    bound=get_light_cycles(3);
    printf("%d light_cycles \n",bound);

}


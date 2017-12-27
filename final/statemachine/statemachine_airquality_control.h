#ifndef STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H
#define STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H

#include "statemachines.h"

#define GREEN 0
#define YELLOW 1
#define RED 2


#define UPPER_TRHESHOLD_AIR_QUALITY 27 /*e.g. when the desired temperature is 25*/
#define LOWER_THRESHOLD_AIR_QUALITY 22

#define TRUE 1
#define FALSE 0


static int air_quality_state=0;
int GetAirQualityState(int n_air);
void Statemachine_AirQuality(void);

#endif //STATEMACHINE_STATEMACHINE_AIRQUALITY_CONTROL_H_H

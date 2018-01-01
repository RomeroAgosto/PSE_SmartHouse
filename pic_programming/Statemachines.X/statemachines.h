#ifndef STATEMACHINES_H
#define	STATEMACHINES_H

#include "AirTemperature/Statemachine_AirTemperature/statemachine_airtemp_control.h"
#include "AirQuality/Statemachine_AirQuality/statemachine_airquality_control.h"
#include "WaterTemperature/Statemachine_Water/statemachine_watertemp_control.h"
#include "LightControl/StatemachineLightControl/statemachine_light_control.h"

#include "stdio.h"
#include <stdlib.h>
#include <string.h>

/* if UNITTEST is 1 a unittest can be performed -> dummyfunction for the sensor/desired value generation are introduced*/
#define UNITTEST 1

#define TRUE 1
#define FALSE 0

#if UNITTEST==0
#include "../Schedules.X/desiredValues.h"
#endif


#endif	/* STATEMACHINES_H */


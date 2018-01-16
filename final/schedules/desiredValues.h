/* 
 * File:   desiredValues.h
 * Author: Ricardo
 *
 * Created on 17 December 2017, 23:59
 */

#ifndef DESIREDVALUES_H
#define	DESIREDVALUES_H

#include "schedules.h"
#include <time.h>
#include "../clock_hall/hallClock.h"
#include <stdio.h>


#define DISABLE -77

int compare_hour(int time1, int time2);

int desired_water_temperature();

int desired_air_temperature(int n_air);

int desired_light(int n_ligth);


#endif	/* DESIREDVALUES_H */


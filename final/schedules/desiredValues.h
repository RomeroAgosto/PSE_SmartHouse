/**
 * @file schedules.h
 * @author Deep Impact
 * @date 15 Dez 2017
 * @brief This file creates a structure to save all the schedules and all the information about each one, such as the id of the associated room, the desired value of temperature when applicable, if it's \
 * enabled or not, the start and stop time.
 * 
 * 
 * Company  Deep Impact
 * 
 * ==============================================
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


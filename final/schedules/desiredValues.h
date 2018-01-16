/**
 * @file schedules.h
 * @author Deep Impact
 * @date 15 Dez 2017
 * @brief This file reads from the schedule structure if there is any schedule active and if so, returns the desired value for water and air temperature, and if the lights should be on or off
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

/**
 * @brief compare_hour, this function will compare the current time with the start and stop time of a given schedule
 * 
 * @param time1-> start time of given schedule
 * @param time1-> stop time of given schedule
 * @return 1 -> if the current time is between those two values, 0 -> if current time is outside given times
 * ==============================================
 */    

int compare_hour(int time1, int time2);

/**
 * @brief desired_water_temperature, this function will return the desired value of water temperature if a schedule is on
 * 
 * @return desired value of water temperature if a schedule is on or -77 if there isn't a active schedule
 * ==============================================
 */

int desired_water_temperature();

/**
 * @brief desired_air_temperature, this function will return the desired value of air temperature if a schedule is on for the room n_air
 * 
 * @param n_air -> number of the room to check
 * @return desired value of air temperature if a schedule is on for the room n_air or -77 if there isn't a active schedule
 * ==============================================
 */

int desired_air_temperature(int n_air);

/**
 * @brief desired_light, this function will return the desired value of the light for room n_light
 * 
 * @param n_light -> number of the room to check
 * @return 1 if the motion detection should be on or -77 if motion detection should be off
 * ==============================================
 */

int desired_light(int n_ligth);


#endif	/* DESIREDVALUES_H */


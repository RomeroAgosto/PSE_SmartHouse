/** \file hallClock.h
* \brief This library include The Clock All of the System
*  
*
* 
*
* \author Samuel Simoes
*
* \date 03-11-2017
*/
#ifndef HALLCLOCK_H
#define HALLCLOCK_H

#include <time.h>
/** 
* \brief Is a setup for clock hall, put the clock hall run in timer 2
* \param  func  Is a pointer to a function that will run alongside with timer
* 
* \author Samuel Simoes
* \date 03-11-2017  
*/
void setup_clockHall(void (*func)(void));

/** 
* \brief This func will save the struct values of clock_hall inside of the pointer
* 
* \author Samuel Simoes
* \date 03-11-2017  
*/
void get_timeHall(struct tm *);
int update_time(struct tm time);
int setup_halfanHour(void (*half_clock)(void));

int get_time(char *to_send);


#endif /*CLOCK_HALL_H*/
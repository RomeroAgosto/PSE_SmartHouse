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
* \brief This func will run the clock at 1Hz in a timer at 2Hz
* 
* \author Samuel Simoes
* \date 03-11-2017  
*/
void inc_clock(void);
/** 
* \brief This func will save the struct values of clock_hall inside of the pointer
* 
* \author Samuel Simoes
* \date 03-11-2017  
*/
void get_timeHall(struct tm *);
int update_time(struct tm );
void increment_time(void);



#endif /*CLOCK_HALL_H*/
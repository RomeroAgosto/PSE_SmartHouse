/**@file  hallClock.h
*  @author Deep Impact
*  @date 15 Dez 2017
*  @brief This library include The Clock All of the System
*  
*
*
* 
*/
#ifndef HALLCLOCK_H
#define HALLCLOCK_H

#include <time.h>
/** 
* @brief Is a setup for clock hall, put the clock hall run in timer 2
* @param  func  Is a pointer to a function that will run alongside with timer
* 
*/
void setup_clock_hall(void (*func)(void));

/** 
* \brief This func will run the clock at 1Hz in a timer at 2Hz
* @brief This func will save the struct values of clock_hall inside of the pointer
* @param  tm  Is a pointer to a structure that will run alongside with timer
* 
*/
void inc_clock(void);
/** 
* \brief This func will save the struct values of clock_hall inside of the pointer
* @brief This func will save the struct values of clock_hall inside of the pointer
* @param  tm  Is a pointer to a structure that will run alongside with timer
* 
*/

void get_timeHall(struct tm *);
int update_time(struct tm );
void increment_time(void);

void get_time_hall(struct tm *);
/** 
* @brief This func will save the time inside of the struture
* @param  time  Is a structure that have the data
* 
*/
int update_time(struct tm time);
/** 
* @brief This function set a timer to run 30 minutes in 30 minutes
* @param  half_clock  Is a pointer to a function that will run alongside with timer
*/
int setup_half_a_hour(void (*half_clock)(void));
/** 
* @brief This function will take the message whit the time a update the pic internal clock
* @param  to_send  mesage whit the data
* 
*/
int get_time(char *to_send);


#endif /*CLOCK_HALL_H*/
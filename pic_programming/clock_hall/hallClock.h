#ifndef HALLCLOCK_H
#define HALLCLOCK_H

#include <time.h>

static struct tm time_hall;

void get_timeHall(struct tm *time);
int update_time(struct tm time_temp);
void increment_time(void);
void wait(double seconds);



#endif /*CLOCK_HALL_H*/
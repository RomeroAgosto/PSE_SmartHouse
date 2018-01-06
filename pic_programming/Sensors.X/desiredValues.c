#include "schedules.h"
#include <time.h>
#include "../Timer_Clock.X/hallClock.h"

#define disable -100

static struct tm tclock;
static int conv_clock=0;

static int desired_AirTemp[8][4];
static int desired_water[4];
static int desired_ligth[4][4];


int compareHour(int time1, int time2)
{
    if(time2<time1) {
        if(conv_clock<time1 || conv_clock>time2) {
            return 1;
        }
    }
    else if(conv_clock>time1 && conv_clock<time2)
        return 1;
    else
        return 0;
}

int  updateTimeDesiredValue()
{
//    get_timeHall(&tclock);
    conv_clock=tclock.tm_hour*100+tclock.tm_min;
    return 0;
}

int desiredWaterTemperature()
{
    int i, maximum;
    maximum=disable;
    for(i=0;i<4;i++)        /* Used 4 because theres's 4 schedule per day of the week */
    {
        if(home.water_temperature.array_room[1].array_schedule[tclock.tm_wday].schedules[i].enable==1)
        {
            if(compareHour(home.water_temperature.array_room[1].array_schedule[tclock.tm_wday].schedules[i].start_time,home.water_temperature.array_room[1].array_schedule[tclock.tm_wday].schedules[i].stop_time))
            {
                desired_water[i]=home.water_temperature.array_room[1].array_schedule[tclock.tm_wday].schedules[i].value;
            }
            else
            {
                desired_water[i]=disable;
            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        if (desired_water[i] > maximum)
        {
            maximum  = desired_water[i];
        }
    }
    return maximum;
}

int desiredAirTemperature(int n_air)
{
    int i, maximum;
    maximum=disable;
    for(i=0;i<4;i++)        /* Used 4 because theres's 4 schedule per day of the week */
    {
        if(home.air_temperature.array_room[n_air].array_schedule[tclock.tm_wday].schedules[i].enable==1)
        {
            if(compareHour(home.air_temperature.array_room[n_air].array_schedule[tclock.tm_wday].schedules[i].start_time,home.air_temperature.array_room[n_air].array_schedule[tclock.tm_wday].schedules[i].stop_time))
            {
                desired_AirTemp[n_air][i]=home.air_temperature.array_room[n_air].array_schedule[tclock.tm_wday].schedules[i].value;
            }
            else
            {
                desired_AirTemp[n_air][i]=disable;
            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        if (desired_AirTemp[n_air][i] > maximum)
        {
            maximum  = desired_AirTemp[n_air][i];
        }
    }
    return maximum;
}

int desiredLigth(int n_ligth)
{
    int i;
    for(i=0;i<4;i++)        /* Used 4 because theres's 4 schedule per day of the week */
    {
        if(home.light.array_room[n_ligth].array_schedule[tclock.tm_wday].schedules[i].enable==1)
        {
            if(compareHour(home.light.array_room[n_ligth].array_schedule[tclock.tm_wday].schedules[i].start_time,home.light.array_room[n_ligth].array_schedule[tclock.tm_wday].schedules[i].stop_time))
            {
                desired_ligth[n_ligth][i]=home.light.array_room[n_ligth].array_schedule[tclock.tm_wday].schedules[i].value;
            }
            else
            {
                desired_ligth[n_ligth][i]=disable;

            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        if (desired_ligth[n_ligth][i] == 1)
        {
            return 1;
        }
    }
    return 0;
}

/* *****************************************************************************
 End of File
 */

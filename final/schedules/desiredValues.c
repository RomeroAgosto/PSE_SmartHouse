#include "schedules.h"
#include <time.h>
#include "../clock_hall/hallClock.h"
#include <stdio.h>
extern house home;
#define disable -100

static struct tm tclock;
static int conv_clock=0;

static int desired_AirTemp[8][4];
static int desired_water[4];
static int desired_ligth[4][4];

int compareHour(int time1, int time2)
{
    
    
    if(time2<time1) {
        if(conv_clock<=time1 || conv_clock>=time2) {
            return 1;
        }
    }
    else if(conv_clock>=time1 && conv_clock<=time2)
        return 1;
    else
        return 0;
}

int  updateTimeDesiredValue()
{
    get_timeHall(&tclock);
    conv_clock=tclock.tm_hour*100+tclock.tm_min;
    return 0;
}

int desiredWaterTemperature()
{
    updateTimeDesiredValue();
    int i, maximum;
    maximum=disable;
    for(i=0;i<4;i++)        /* Used 4 because theres's 4 schedule per day of the week */
    {      
      
    printf("id %d\n\r",getEnable(0,0,tclock.tm_wday,0));
    printf("value %d\n\r",getValue(0,0,tclock.tm_wday,0));
    printf("enable %d\n\r",getEnable(0,0,tclock.tm_wday,0));
    printf("start %d\n\r",getStartTime(0,0,tclock.tm_wday,0));
    printf("end %d\n\r",getStopTime(0,0,tclock.tm_wday,0));
        
        if(getEnable(0,0,tclock.tm_wday,i)==1)
        {
            if(compareHour(getStartTime(0,0,tclock.tm_wday,i),getStopTime(0,0,tclock.tm_wday,i)))
            {
                desired_water[i]=getValue(0,0,tclock.tm_wday,i);
            }
            else
            {
                desired_water[i]=disable;
            }
        }
        else {
            desired_water[i]=disable;
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
    updateTimeDesiredValue();
    int i, maximum;
    maximum=disable;
    for(i=0;i<4;i++)        /* Used 4 because theres's 4 schedule per day of the week */
    {
        if(getEnable(1,n_air,tclock.tm_wday,i)==1)
        {
            if(compareHour(getStartTime(1,n_air,tclock.tm_wday,i),getStopTime(1,n_air,tclock.tm_wday,i)))
            {
                desired_AirTemp[n_air][i]=getValue(1,n_air,tclock.tm_wday,i);
            }
            else
            {
                desired_AirTemp[n_air][i]=disable;
            }
        }
        else {
            desired_AirTemp[n_air][i]=disable;
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

int desiredLight(int n_ligth)
{
    updateTimeDesiredValue();
    int i;
    for(i=0;i<4;i++)        /* Used 4 because theres's 4 schedule per day of the week */
    {
        if(getEnable(2,n_ligth,tclock.tm_wday,i)==1)
        {
            if(compareHour(getStartTime(2,n_ligth,tclock.tm_wday,i),getStopTime(2,n_ligth,tclock.tm_wday,i)))
            {
                desired_ligth[n_ligth][i]=getValue(2,n_ligth,tclock.tm_wday,i);
            }
            else
            {
                desired_ligth[n_ligth][i]=disable;

            }
        }
        else {
            desired_ligth[n_ligth][i]=disable;
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

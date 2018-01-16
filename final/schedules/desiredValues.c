#include "desiredValues.h"


static struct tm tclock;
static int conv_clock=0;

static int desired_AirTemp[8][4];
static int desired_water[4];
static int desired_ligth[4][4];

int compare_hour(int time1, int time2)
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
    get_time_hall(&tclock);
    conv_clock=tclock.tm_hour*100+tclock.tm_min;
    return 0;
}

int desired_water_temperature()
{
    updateTimeDesiredValue();
    int i, maximum;
    maximum=DISABLE;
    for(i=0;i<4;i++)        /* Used 4 because theres's 4 schedule per day of the week */
    {      
      
    /*printf("id %d\n\r",get_enable(0,0,tclock.tm_wday,0));
    printf("value %d\n\r",get_value(0,0,tclock.tm_wday,0));
    printf("enable %d\n\r",get_enable(0,0,tclock.tm_wday,0));
    printf("start %d\n\r",get_start_time(0,0,tclock.tm_wday,0));
    printf("end %d\n\r",get_stop_time(0,0,tclock.tm_wday,0));*/ /*just for test*/
        
        if(get_enable(0,0,tclock.tm_wday,i)==1)
        {
            if(compare_hour(get_start_time(0,0,tclock.tm_wday,i),get_stop_time(0,0,tclock.tm_wday,i)))
            {
                desired_water[i]=get_value(0,0,tclock.tm_wday,i);
            }
            else
            {
                desired_water[i]=DISABLE;
            }
        }
        else {
            desired_water[i]=DISABLE;
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

int desired_air_temperature(int n_air)
{
    updateTimeDesiredValue();
    int i, maximum;
    maximum=DISABLE;
    for(i=0;i<4;i++)        /* Used 4 because theres's 4 schedule per day of the week */
    {
        if(get_enable(1,n_air,tclock.tm_wday,i)==1)
        {
            if(compare_hour(get_start_time(1,n_air,tclock.tm_wday,i),get_stop_time(1,n_air,tclock.tm_wday,i)))
            {
                desired_AirTemp[n_air][i]=get_value(1,n_air,tclock.tm_wday,i);
            }
            else
            {
                desired_AirTemp[n_air][i]=DISABLE;
            }
        }
        else {
            desired_AirTemp[n_air][i]=DISABLE;
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

int desired_light(int n_ligth)
{
    updateTimeDesiredValue();
    int i;
    for(i=0;i<4;i++)        /* Used 4 because theres's 4 schedule per day of the week */
    {
        if(get_enable(2,n_ligth,tclock.tm_wday,i)==1)
        {
            if(compare_hour(get_start_time(2,n_ligth,tclock.tm_wday,i),get_stop_time(2,n_ligth,tclock.tm_wday,i)))
            {
                desired_ligth[n_ligth][i]=1;
            }
            else
            {
                desired_ligth[n_ligth][i]=DISABLE;

            }
        }
        else {
            desired_ligth[n_ligth][i]=DISABLE;
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

#include "hallClock.h"
#include <stdio.h>
#include <string.h>


static int dayMonMax[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

// copy the time_hall to time
void get_timeHall(struct tm *time)
{
    *time=time_hall;
}

// save new time in time_hall
int update_time(struct tm time_temp)
{
    time_hall=time_temp;
    if(time_hall.tm_year%4==0 && (time_hall.tm_year%100!=0 || (time_hall.tm_year+1900)%400==0))
    {
        dayMonMax[1]=29;
    }
    else
    {
        dayMonMax[1]=28;
    }
    return 0;
}

// will runs every second
void increment_time(void)
{
    
    time_hall.tm_sec=(time_hall.tm_sec+1)%60;   // increment sec
    
    if(time_hall.tm_sec==0)
    {    
        time_hall.tm_min=(time_hall.tm_min+1)%60;      // increment min
        
        if(time_hall.tm_min==0)   
        {
            time_hall.tm_hour=(time_hall.tm_hour+1)%24;  //increment hour     
            
            if(time_hall.tm_hour==0) 
            {   
                time_hall.tm_mday=(time_hall.tm_mday+1)%(dayMonMax[time_hall.tm_mon]+1);  // increment month-day
                time_hall.tm_wday=(time_hall.tm_wday+1)%7;                                // increment week-day
                time_hall.tm_yday++;                                                      // increment year-day
                
                if(time_hall.tm_mday==0)
                {
                    time_hall.tm_mday=1;                            // if day is 0 change to 1
                    time_hall.tm_mon=(time_hall.tm_mon+1)%12;       // increment month
        
                    if(time_hall.tm_mon==0)
                    {
                        time_hall.tm_yday=0;    // reset year-day
                        time_hall.tm_year++;    // increment year
                    
                    // -» In beging off a leap year, set dayMonMax[1]=29
                    if(time_hall.tm_mon==1)    
                    {
                        if(time_hall.tm_year%4==0 && (time_hall.tm_year%100!=0 || (time_hall.tm_year+1900)%400==0))
                        {
                            dayMonMax[1]=29;
                        }
                        else
                        {
                            dayMonMax[1]=28;
                        }
                    }
                    }
                }
            }
        }
    }
    printf("day:%d hours:%d, minutes:%d, seconds:%d\n",time_hall.tm_mday,time_hall.tm_hour,time_hall.tm_min,time_hall.tm_sec);
}

/**@brief wait brings the pic to wait for a number of seconds
/* @param input in seconds
 * @author Sascha Marquardt
 * @date 03-11-2017  
 */
void wait(double seconds){
    /* save start time */
  /*  const time_t start = mktime(&time_hall);

    time_t current;
    do{
        /* get current time */
      /*  current=mktime(&time_hall);
        printf("%f",difftime(current,start));

        /* break loop when the requested number of seconds have elapsed */
   /* }while(difftime(current, start) < seconds);*/
}
/* *****************************************************************************
 End of File
 */

#include "schedules.h"
#include <time.h>
#include "../clock_hall/hallClock.h"

static struct tm tclock;

static int desired_AirTemp[8][4]={-100};
static int desired_water[4]={-100};
static int desired_ligth[8][4]={0};

int ds_initDSchedules()
{
    
    return 0;
}

int  ds_updateDSchedules_time()
{
    get_timeHall(&tclock);
    return 0;
}

int ds_DesiredWaterTemp()
{
    int i, maximum;
    maximum=disable;
    for(i=0;i<4;i++)
    {
        if(house.water_temperature.array_room[1].array_schedule[tclock.tm_wday].schedules[i].enable==1)
        {
            if(compareHour(house.water_temperature.array_room[1].array_schedule[tclock.tm_wday].schedules[i].start_time))
            {    
                desired_water[i]=house.water_temperature.array_room[1].array_schedule[tclock.tm_wday].schedules[i].value;
            }
            else if(compareHour(house.water_temperature.array_room[1].array_schedule[tclock.tm_wday].schedules[i].start_time))
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

int ds_DesiredAirTemp(int n_air)
{
    int i, maximum;
    maximum=disable;
    for(i=0;i<4;i++)
    {
        if(house.air_temperature.array_room[n_air].array_schedule[tclock.tm_wday].schedules[i].enable==1)
        {
            if(compareHour(house.air_temperature.array_room[n_air].array_schedule[tclock.tm_wday].schedules[i].start_time))
            {    
                desired_AirTemp[n_air][i]=house.air_temperature.array_room[n_air].array_schedule[tclock.tm_wday].schedules[i].value;
            }
            else if(compareHour(house.air_temperature.array_room[n_air].array_schedule[tclock.tm_wday].schedules[i].start_time))
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

int ds_DesiredLigth(int n_ligth)
{
    int i;
    for(i=0;i<4;i++)
    {
        if(house.light.array_room[n_ligth].array_schedule[tclock.tm_wday].schedules[i].enable==1)
        {
            if(compareHour(house.light.array_room[n_ligth].array_schedule[tclock.tm_wday].schedules[i].start_time))
            {    
                desired_ligth[n_ligth][i]=house.light.array_room[n_ligth].array_schedule[tclock.tm_wday].schedules[i].value;
            }
            else if(compareHour(house.light.array_room[n_ligth].array_schedule[tclock.tm_wday].schedules[i].start_time))
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

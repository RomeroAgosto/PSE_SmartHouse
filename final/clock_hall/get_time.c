#include <time.h>
#include <stdio.h>
static time_t read_time;
int get_time(char *to_send)
{
    struct tm time;

    int i,year_value,month_value,day_value,hour_value,minute_value,second_value;
    char n_year[4], n_month[2], n_day[2],n_hour[2],n_min[2], n_sec[2],weekday_value;
    // message format #@AAAAMMWDDHHmmss
    for(i=0;i<4;i++)
    {
        n_year[i]=to_send[i+2];
    }
    for (i = 0; i < 2; i++) {
        n_month[i]=to_send[i+6];
        n_day[i]=to_send[i+9];
        n_hour[i]=to_send[i+11];
        n_min[i]=to_send[i+13];
        n_sec[i]=to_send[i+15];
    }
    weekday_value=to_send[8];
    sscanf(n_year,"%4d",&year_value);
    sscanf(n_month,"%2d",&month_value);
    sscanf(n_day,"%2d",&day_value);
    sscanf(n_hour,"%2d",&hour_value);
    sscanf(n_min,"%2d",&minute_value);
    sscanf(n_sec,"%2d",&second_value);

    time.tm_year=year_value-1900;
    time.tm_mon=month_value-1;      /*! jan=1/dez=12 */
    time.tm_wday=weekday_value-'1'; /*! Monday=1/sunday=7 */
    time.tm_mday=day_value;
    time.tm_hour=hour_value;
    time.tm_min=minute_value;
    time.tm_sec=second_value;
    
    printf("A-Hour: %d, Min: %d\n\r", time.tm_hour, time.tm_min);
    update_time(time);
    return 0;
}

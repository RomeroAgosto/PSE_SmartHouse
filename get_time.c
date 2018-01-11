#include <time.h>
#include <stdio.h>
static time_t read_time;
int get_time(char *to_send)
{
    struct tm *prt_ts;
    time(&read_time);
    prt_ts=gmtime(&read_time);

    int i,year_value,month_value,day_value,hour_value,minute_value,second_value;
    char n_year[4], n_month[2], n_day[2],n_hour[2],n_min[2], n_sec[2],weekday_value;
    // message format #@AAAAMMWDDHHmmss
    for(i=0;i<4;i++)
    {
        n_year[i]=to_send[i+2];
    }
    for (int i = 0; i < 2; i++) {
        n_month[i]=to_send[i+6];
        n_day[i]=to_send[i+9];
        n_hour[i]=to_send[i+11];
        n_min[i]=to_send[i+13];
        n_sec[i]=to_send[i+15];
    }
    weekday_value=to_send[8];
    sscanf(n_year,"%4d",&year_value);
    sscanf(n_month,"%2d",&month_value);
    sscanf(n_day,"%4d",&day_value);
    sscanf(n_hour,"%2d",&hour_value);
    sscanf(n_min,"%2d",&minute_value);
    sscanf(n_sec,"%2d",&second_value);

    prt_ts->tm_year=year_value-1900;
    prt_ts->tm_mon=month_value-1;
    prt_ts->tm_wday=weekday_value-'0';
    prt_ts->tm_mday=day_value;
    prt_ts->tm_hour=hour_value;
    prt_ts->tm_min=minute_value;
    prt_ts->tm_sec=second_value;


}

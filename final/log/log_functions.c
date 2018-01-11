#include <stdio.h>
#include <stdlib.h>
#include "log_stru.h"
#include "struct_lib.h"
#include <time.h>
#include <string.h>
#include "update.h"
#include "log_functions.h"

static sensorvalues sensor_values;
static log msd;
static time_t read_time;
int log_data_saving()
{
    struct tm time;

    get_timeHall(&time);

    static int i=0;
    int j;
    if(i==49) i=0;
    if(i>=0 && i<48)
    {
        //mesure_time
        msd.data[i].sensor_data[0]=(time.tm_year)+1900;
        msd.data[i].sensor_data[1]=(time.tm_mon )+1;
        msd.data[i].sensor_data[2]=time.tm_mday;
        msd.data[i].sensor_data[3]=time.tm_hour;
        msd.data[i].sensor_data[4]=time.tm_min;


        //data from air temperature

        for(j=0;j<8;j++)
        {
            msd.data[i].sensor_data[j+5]=GetAirTemperature(j);//sensor_values.air_temperature_sensor[j].temp;
            msd.data[i].sensor_data[j+13]=//sensor_values.air_temperature_sensor[j].heater;
        }

        //data from water control
        msd.data[i].sensor_data[21]=GetWaterTemperature();//sensor_values.water_temperature.temp;
        msd.data[i].sensor_data[22]=GetWaterHeater();//sensor_values.water_temperature.water_heater
        // data air quality
        for(j=0;j<4;j++) {
            msd.data[i].sensor_data[j+23] =GetVentilatorState();// sensor_values.air_quality_sensor[j].ventilator;
        }

        i++;
    }

}
int log_create_msg(char *message)
{
    strcpy(message,"#");
    char end_indicator[3];
    strcpy(end_indicator,"]*");
    char temp_message[3000];
    int j;
    for(j=0;j<48;j++)
    {
        sprintf(temp_message,"{\"time\":[\"%d\",\"%d\",\"%d\",\"%d\",\"%d\"\n],"
                        "      \"air_temp\":[\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\"],\n"
                        "      \"air_status\":[\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\"],\n"
                        "      \"water_temp\":\"%d\",\"water_state\":\"%d\",\n"
                        "       \"air_quality\":[\"%d\",\"%d\",\"%d\",\"%d\"] }\n",
                msd.data[j].sensor_data[0], msd.data[j].sensor_data[1], msd.data[j].sensor_data[2], msd.data[j].sensor_data[3], msd.data[j].sensor_data[4],
                msd.data[j].sensor_data[5], msd.data[j].sensor_data[6], msd.data[j].sensor_data[7], msd.data[j].sensor_data[8], msd.data[j].sensor_data[9],msd.data[j].sensor_data[10], msd.data[j].sensor_data[11], msd.data[j].sensor_data[12],
                msd.data[j].sensor_data[13],msd.data[j].sensor_data[14], msd.data[j].sensor_data[15], msd.data[j].sensor_data[16], msd.data[j].sensor_data[17],msd.data[j].sensor_data[18], msd.data[j].sensor_data[19], msd.data[j].sensor_data[20],
                msd.data[j].sensor_data[21],msd.data[j].sensor_data[22],msd.data[j].sensor_data[23],msd.data[j].sensor_data[24],msd.data[j].sensor_data[25],msd.data[j].sensor_data[26]
        );

        strcat(message,temp_message);
    }
    strcat(message,end_indicator);
}
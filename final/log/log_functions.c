#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../update/update.h"
#include "log_functions.h"
#include "log_stru.h"
#include "../Statemachines.X/AirQuality/Statemachine_AirQuality/statemachine_airquality_control.h"

static log msd;
static time_t read_time;
static unsigned int log_save_flag=1;
static int counter_log=0;

void setLogFlag()
{
    log_save_flag=1;
}

int log_data_saving()
{
    if(log_save_flag==0)    /*!If log_save_flag is false the function doesn't save the log*/
    {
        return 0;
    }
    
    struct tm time;

    get_time_hall(&time);

    int j;
    if(counter_log==48) {counter_log=0;} /*!Reset Counter*/
    
        //mesure_time
        msd.data[counter_log].sensor_data[0]=(time.tm_year)+1900;
        msd.data[counter_log].sensor_data[1]=(time.tm_mon )+1;
        msd.data[counter_log].sensor_data[2]=time.tm_mday;
        msd.data[counter_log].sensor_data[3]=time.tm_hour;
        msd.data[counter_log].sensor_data[4]=time.tm_min;


        //data from air temperature

        for(j=0;j<8;j++)
        {
            msd.data[counter_log].sensor_data[j+5]=GetAirTemperature(j);//sensor_values.air_temperature_sensor[j].temp;
            msd.data[counter_log].sensor_data[j+13]=GetHeatingAirState(j);//sensor_values.air_temperature_sensor[j].heater;
        }

        //data from water control
        msd.data[counter_log].sensor_data[21]=GetWaterTemperature();//sensor_values.water_temperature.temp;
        msd.data[counter_log].sensor_data[22]=GetWaterHeater();//sensor_values.water_temperature.water_heater
        // data air quality
        for(j=0;j<4;j++) {
            msd.data[counter_log].sensor_data[j+23] =GetAirQualityState(j);// sensor_values.air_quality_sensor[j].ventilator;
        }

    counter_log++;
    
    log_save_flag=0;
}
int log_create_msg(char *message)
{
    static char temp_message[3000];
    
    if(counter_log==0) /*The data log it is clean*/
    {
         strcpy(message,"#*");
         return 0;
    }
    char end_indicator[3];
    
    strcpy(message,"#[");
    strcpy(end_indicator,"]*");
    
    strcpy(temp_message,"");
    int j;
    for(j=0;j<counter_log;j++)
    {
        sprintf(temp_message,"{\"time\":[\"%d\",\"%d\",\"%d\",\"%d\",\"%d\"],\n"
                        "\"air_temp\":[\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\"],\n"
                        "\"air_status\":[\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\"],\n"
                        "\"water_temp\":\"%d\",\"water_state\":\"%d\",\n"
                        "\"air_quality\":[\"%d\",\"%d\",\"%d\",\"%d\"] }\n",
                msd.data[j].sensor_data[0], msd.data[j].sensor_data[1], msd.data[j].sensor_data[2], msd.data[j].sensor_data[3], msd.data[j].sensor_data[4],
                msd.data[j].sensor_data[5], msd.data[j].sensor_data[6], msd.data[j].sensor_data[7], msd.data[j].sensor_data[8], msd.data[j].sensor_data[9],msd.data[j].sensor_data[10], msd.data[j].sensor_data[11], msd.data[j].sensor_data[12],
                msd.data[j].sensor_data[13],msd.data[j].sensor_data[14], msd.data[j].sensor_data[15], msd.data[j].sensor_data[16], msd.data[j].sensor_data[17],msd.data[j].sensor_data[18], msd.data[j].sensor_data[19], msd.data[j].sensor_data[20],
                msd.data[j].sensor_data[21],msd.data[j].sensor_data[22],
                msd.data[j].sensor_data[23],msd.data[j].sensor_data[24],msd.data[j].sensor_data[25],msd.data[j].sensor_data[26]
        );
        if(j != counter_log-1)
        {
            strcat(temp_message,",");
        }
        strcat(message,temp_message);
    }
    strcat(message,end_indicator);
    counter_log=0; /*reset counter_log*/
}
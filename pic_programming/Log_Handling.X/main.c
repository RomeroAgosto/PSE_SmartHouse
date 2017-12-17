#include <stdio.h>
#include <stdlib.h>
#include "log_functions.h"
#include "struct_lib.h"
#include <time.h>
#include <string.h>


sensorvalues sensor_values;
log msd;
time_t read_time;

int main()
{
    int k;
    char message[120000];
    for(k=0;k<8;k++)
    {
        sensor_values.air_temperature_sensor[k].temp=(double) k;
    }
	for(k=0;k<8;k++)
    {
        sensor_values.air_temperature_sensor[k].state=(double) k;
    }
	
        sensor_values.water_temperature.temp=1;
		sensor_values.water_temperature.water_heater=2;
    
	for(k=0;k<4;k++)
    {
       sensor_values.air_quality_sensor[k].state=(double) k;
    }
	for(k=0;k<24;k++)
    {
    log_data_saving();
	}
	//---------------------------------------------
	    for(k=0;k<8;k++)
    {
        sensor_values.air_temperature_sensor[k].temp=((double) k+1);
    }
	for(k=0;k<8;k++)
    {
        sensor_values.air_temperature_sensor[k].state=((double) k+1);
    }
	
        sensor_values.water_temperature.temp=9;
		sensor_values.water_temperature.water_heater=22;
    
	for(k=0;k<4;k++)
    {
       sensor_values.air_quality_sensor[k].state=(double) k+1;
    }
	for(k=0;k<24;k++)
    {
    log_data_saving();
	}
//--------------------
	
    log_create_msg(message);
    printf("%s",message);


}
/*
int log_data_saving()
{
    struct tm *prt_ts;
    time(&read_time);
    prt_ts=gmtime(&read_time);

    static int i=0;
    if(i==48) i=0;
    if(i>=0 && i<48)
    {
        //mesure_time
        msd.data[i].sensor_data[0]=(prt_ts->tm_year)+1900;
        msd.data[i].sensor_data[1]=(prt_ts->tm_mon )+1;
        msd.data[i].sensor_data[2]=prt_ts->tm_mday;
        msd.data[i].sensor_data[3]=prt_ts->tm_hour;
        msd.data[i].sensor_data[4]=prt_ts->tm_min;

        
        //data from air temperature
        msd.data[i].sensor_data[5]=sensor_values.air_temperature_sensor[0].temp;
        msd.data[i].sensor_data[6]=sensor_values.air_temperature_sensor[1].temp;
        msd.data[i].sensor_data[7]=sensor_values.air_temperature_sensor[2].temp;
        msd.data[i].sensor_data[8]=sensor_values.air_temperature_sensor[3].temp;
        msd.data[i].sensor_data[9]=sensor_values.air_temperature_sensor[4].temp;
        msd.data[i].sensor_data[10]=sensor_values.air_temperature_sensor[5].temp;
        msd.data[i].sensor_data[11]=sensor_values.air_temperature_sensor[6].temp;
        msd.data[i].sensor_data[12]=sensor_values.air_temperature_sensor[7].temp;
        msd.data[i].sensor_data[13]=sensor_values.air_temperature_sensor[0].state;
        msd.data[i].sensor_data[14]=sensor_values.air_temperature_sensor[1].state;
        msd.data[i].sensor_data[15]=sensor_values.air_temperature_sensor[2].state;
        msd.data[i].sensor_data[16]=sensor_values.air_temperature_sensor[3].state;
        msd.data[i].sensor_data[17]=sensor_values.air_temperature_sensor[4].state;
        msd.data[i].sensor_data[18]=sensor_values.air_temperature_sensor[5].state;
        msd.data[i].sensor_data[19]=sensor_values.air_temperature_sensor[6].state;
        msd.data[i].sensor_data[20]=sensor_values.air_temperature_sensor[7].state;
        //data from water control
        msd.data[i].sensor_data[21]=sensor_values.water_temperature.temp;
        msd.data[i].sensor_data[22]=sensor_values.water_temperature.water_heater;
        // data air quality
        msd.data[i].sensor_data[23]=sensor_values.air_quality_sensor[0].state;
        msd.data[i].sensor_data[24]=sensor_values.air_quality_sensor[1].state;
        msd.data[i].sensor_data[25]=sensor_values.air_quality_sensor[2].state;
        msd.data[i].sensor_data[26]=sensor_values.air_quality_sensor[3].state;
        i++;
    }

}

int log_create_msg(char *message)
{
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

}*/

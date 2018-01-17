#include "log_functions.h"
#include "log_stru.h"

static log data;
static time_t read_time;
static unsigned int log_save_flag=1;
static int counter_log=0;

void set_log_flag(){
    log_save_flag=1;
}

int log_data_saving(){
    if(log_save_flag==0){    /*!If log_save_flag is false the function doesn't save the log*/
    
        return 0;
    }
    
    struct tm time;

    get_time_hall(&time);

    int j;
    if(counter_log==48) {counter_log=0;} /*!Reset Counter*/
    
        //mesure_time
        data[counter_log].sensor_data[0]=(time.tm_year)+1900;
        data[counter_log].sensor_data[1]=(time.tm_mon )+1;
        data[counter_log].sensor_data[2]=time.tm_mday;
        data[counter_log].sensor_data[3]=time.tm_hour;
        data[counter_log].sensor_data[4]=time.tm_min;

        
        //data from air temperature

        for(j=0;j<8;j++){
            data[counter_log].sensor_data[j+5]=get_air_temperature(j);//sensor_values.air_temperature_sensor[j].temp;
            data[counter_log].sensor_data[j+13]=get_heating_air_state(j);//sensor_values.air_temperature_sensor[j].heater;
        }

        //data from water control
        data[counter_log].sensor_data[21]=get_water_temperature();//sensor_values.water_temperature.temp;
        data[counter_log].sensor_data[22]=get_water_heater();//sensor_values.water_temperature.water_heater
        // data air quality
        for(j=0;j<4;j++) {
            data[counter_log].sensor_data[j+23] =get_air_quality_state(j);// sensor_values.air_quality_sensor[j].ventilator;
        }
    counter_log++;
    
    log_save_flag=0;
}
int log_create_msg(char *message){
    static char temp_message[3000];
    
    if(counter_log==0){ /*The data log it is clean*/
    
         strcpy(message,"#*");
         return 0;
    }
    char end_indicator[3];
    
    strcpy(message,"#[");
    strcpy(end_indicator,"]*");
    
    strcpy(temp_message,"");
    int j;
    for(j=0;j<counter_log;j++){
        sprintf(temp_message,"{\"time\":[\"%d\",\"%d\",\"%d\",\"%d\",\"%d\"],\n"    //1,2,3,4,5
                        "\"air_temp\":[\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\"],\n" //6,7,8,9,10,11,12,13
                        "\"air_heater\":[\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\",\"%d\"],\n"   //14,15,16,17,18,19,20,21
                        "\"water_temp\":\"%d\",\"water_heater\":\"%d\",\n" // 22,23
                        "\"air_quality\":[\"%d\",\"%d\",\"%d\",\"%d\"] }\n", //24,25,26,27
                data[j].sensor_data[0], data[j].sensor_data[1], data[j].sensor_data[2], data[j].sensor_data[3], data[j].sensor_data[4], //1,2,3,4,5
                data[j].sensor_data[5], data[j].sensor_data[6], data[j].sensor_data[7], data[j].sensor_data[8], data[j].sensor_data[9],data[j].sensor_data[10], data[j].sensor_data[11], data[j].sensor_data[12], //6,7,8,9,10,11,12,13
                data[j].sensor_data[13],data[j].sensor_data[14], data[j].sensor_data[15], data[j].sensor_data[16], data[j].sensor_data[17],data[j].sensor_data[18], data[j].sensor_data[19], data[j].sensor_data[20],
                data[j].sensor_data[21],data[j].sensor_data[22],
                data[j].sensor_data[23],data[j].sensor_data[24],data[j].sensor_data[25],data[j].sensor_data[26]
        );
        if(j != counter_log-1){
            strcat(temp_message,",");
        }
        strcat(message,temp_message);
    }
    strcat(message,end_indicator);
    counter_log=0; /*reset counter_log*/
}
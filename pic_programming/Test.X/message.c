#include <string.h>
#include <stdio.h>


#define SEND_NO_MESSAGE 0
#define SEND_NEW_STATUS 1
#define SEND_SCHEDULES 2
#define RECEIVE_SCHEDULES 3
#define SEND_DATALOG 4

create_message(int message_flag, char *message) {


    if (message_flag == SEND_NO_MESSAGE) {
        message = "#*";
    }
    else if(message_flag==SEND_NEW_STATUS){
        create_normal_message(message);
    }
    else if(message_flag==SEND_SCHEDULES){
        send_schedules(message);
    }
    else if(message_flag==RECEIVE_SCHEDULES){
        get_schedules();
    }
    else if(message_flag==SEND_DATALOG){

    }

}
int get_schedules(){

}
int send_schedules(){ /*is supposed to be in the schedule file*/
}
int create_normal_message(char *message){
        sprintf(message,""
            "{\"water_data\"\n"
                  ":{\"temp\":\"%f\",\n"
            "            \"desired_value\":\"%d\",\"water_heater\":\"%d\"},\n"
            "            \"light_data\":[\n"
            "             {\"movement_sensor\":\"%d\",\"\"mechanical_switch\":\"%d\",\"\"cycles\":\"%d\"},\n"
            "             {\"movement_sensor\":\"%d\",\"\"mechanical_switch\":\"%d\",\"\"cycles\":\"%d\"},\n"
            "             {\"movement_sensor\":\"%d\",\"\"mechanical_switch\":\"%d\",\"\"cycles\":\"%d\"},\n"
            "             {\"movement_sensor\":\"%d\",\"\"mechanical_switch\":\"%d\",\"\"cycles\":\"%d\"},\n"
            "             {\"movement_sensor\":\"%d\",\"\"mechanical_switch\":\"%d\",\"\"cycles\":\"%d\"},\n"
            "             {\"movement_sensor\":\"%d\",\"\"mechanical_switch\":\"%d\",\"\"cycles\":\"%d\"},\n"
            "             {\"movement_sensor\":\"%d\",\"\"mechanical_switch\":\"%d\",\"\"cycles\":\"%d\"},\n"
            "             {\"movement_sensor\":\"%d\",\"mechanical_switch\":\"%d\",\"\"cycles\":\"%d\"}],\n"
            "       \"air_quality\":{\n"
            "               \"rooms\":[\n"
            "                    {\"air_quality_state\":\"&d\"},\n"
            "                    {\"air_quality_state\":\"&d\"},\n"
            "                    {\"air_quality_state\":\"&d\"}],\"\n"
            "                    fan\":\"%d\"},\n"
            "\"air_temperature\":[\n"
            "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"
            "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"
            "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"
            "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"
            "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"
            "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"
            "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"
            "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"}]}\n",1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,
    18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44);
}



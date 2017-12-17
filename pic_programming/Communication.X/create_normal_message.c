
#include "message.h"

int create_normal_message(char *message){
    sprintf(message,"#"
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
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"}]}*\n",1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,
            18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44);
    printf("%s",message);
}
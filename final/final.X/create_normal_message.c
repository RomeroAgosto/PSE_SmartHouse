
#include "send_receive_messages.h"
#include "update.h"

int create_normal_message(char *message){
    sprintf(message,"#"
                    "{\"water_data\"\n"
                    ":{\"temp\":\"%d\",\n"
                    "            \"desired_value\":\"%d\",\"water_heater\":\"%d\"},\n"
                    "            \"light_data\":[\n"
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"},\n"
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"},\n"
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"},\n"
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"},\n"
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"},\n"
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"},\n"
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"},\n"
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"}],\n"
                    "       \"air_quality\":{\n"
                    "               \"rooms\":[\n"
                    "                    {\"air_quality_state\":\"%d\"},\n"
                    "                    {\"air_quality_state\":\"%d\"},\n"
                    "                    {\"air_quality_state\":\"%d\"},\n"
                    "                    {\"air_quality_state\":\"%d\"}],\n"
                    "                    \"fan\":\"%d\"},\n"
                    "\"air_temperature\":[\n"
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"}]}*\n",GetWaterTemperature(),2,GetWaterHeater(),GetLigthControl(0),GetLightState(0),GetLigthControl(1),GetLightState(1),GetLigthControl(2), GetLightState(2),GetLigthControl(3),GetLightState(3),12,13,14,15,16,17,
            18,19,20,21,22,23,24,25,26,27,GetVentilatorState(),GetVentilatorState(),GetVentilatorState(),GetVentilatorState(),32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48);
    printf("%s",message);
}
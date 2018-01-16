#include "create_normal_message.h"

int create_normal_message(char *message){
    sprintf(message,"#"
                    "{\"water_data\"\n"
                    ":{\"temp\":\"%d\",\n"                                                                         //1
                    "            \"desired_value\":\"%d\",\"water_heater\":\"%d\"},\n"                             //2 3
                    "            \"light_data\":[\n"
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"},\n"        //4 5 6
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"},\n"        //7 8 9
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"},\n"        //10 11 12
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"},\n"        //13 14 15
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"},\n"        //16 17 18
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"},\n"        //19 20 21
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"},\n"        //22 23 24
                    "             {\"movement_sensor\":\"%d\",\"light_state\":\"%d\",\"cycles\":\"%d\"}],\n"       //25 26 27
                    "       \"air_quality\":{\n"
                    "               \"rooms\":[\n"
                    "                    {\"air_quality_state\":\"%d\"},\n"                                        //28
                    "                    {\"air_quality_state\":\"%d\"},\n"                                        //29
                    "                    {\"air_quality_state\":\"%d\"},\n"                                        //30
                    "                    {\"air_quality_state\":\"%d\"}],\n"                                       //31
                    "                    \"fan\":\"%d\"},\n"                                                       //32
                    "\"air_temperature\":[\n"
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"                                   //33 34
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"                                   //35 36
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"                                   //37 38
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"                                   //39 40
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"                                   //41 42
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"                                   //43 44
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"},\n"                                   //45 46
                    "            {\"air_temp\":\"%d\",\"air_heater\":\"%d\"}]}*\n"                                 //47 48
            ,GetWaterTemperature(),desiredWaterTemperature(),GetWaterHeater(),  //1 2 3
            GetLightControl(0),GetLightState(0),GetCycle(0), //4 5 6
            GetLightControl(1),GetLightState(1),GetCycle(1), //7 8 9
            GetLightControl(2),GetLightState(2),GetCycle(2), // 10 11 12
            GetLightControl(3),GetLightState(3),GetCycle(3), // 13 14 15
            0,0,0,0,0,0,0,0,0,0,0,0, // 16 -27
            GetAirQualityState(0),GetAirQualityState(1),GetAirQualityState(2),GetAirQualityState(3), GetVentilatorState(),// 28 29 30 31 32
            GetAirTemperature(0),GetHeatingAirState(0),GetAirTemperature(1),GetHeatingAirState(1), //33 34 35 36
            GetAirTemperature(2),GetHeatingAirState(2),GetAirTemperature(3),GetHeatingAirState(3),// 37 38 39 40
            GetAirTemperature(4),GetHeatingAirState(4),GetAirTemperature(5),GetHeatingAirState(5),//41 42 43 44
            GetAirTemperature(6),GetHeatingAirState(6),GetAirTemperature(7),GetHeatingAirState(7));//45 46 47 48
    printf("%s",message);
}
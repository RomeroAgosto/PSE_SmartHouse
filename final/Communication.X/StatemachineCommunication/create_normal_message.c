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
            ,get_water_temperature(),desired_water_temperature(),get_water_heater(),  //1 2 3
            get_light_control(0),get_light_state(0),get_light_cycles(0), //4 5 6
            get_light_control(1),get_light_state(1),get_light_cycles(1), //7 8 9
            get_light_control(2),get_light_state(2),get_light_cycles(2), // 10 11 12
            get_light_control(3),get_light_state(3),get_light_cycles(3), // 13 14 15
            0,0,0,0,0,0,0,0,0,0,0,0, // 16 -27
            get_air_quality_state(0),get_air_quality_state(1),get_air_quality_state(2),get_air_quality_state(3), get_ventilator_state(),// 28 29 30 31 32
            get_air_temperature(0),get_heating_air_state(0),get_air_temperature(1),get_heating_air_state(1), //33 34 35 36
            get_air_temperature(2),get_heating_air_state(2),get_air_temperature(3),get_heating_air_state(3),// 37 38 39 40
            get_air_temperature(4),get_heating_air_state(4),get_air_temperature(5),get_heating_air_state(5),//41 42 43 44
            get_air_temperature(6),get_heating_air_state(6),get_air_temperature(7),get_heating_air_state(7));//45 46 47 48
    //printf("%s",message);
}
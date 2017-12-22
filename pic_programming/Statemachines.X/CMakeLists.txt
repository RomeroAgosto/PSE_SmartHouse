cmake_minimum_required(VERSION 3.8)
project(Statemachines_X)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.c
        #statemachine_airquality_control.c
        #statemachine_airquality_control.h
        Statemachine_AirTemperature/Statemachine_AirTemperature/statemachine_airtemp_control.c
        Statemachine_AirTemperature/Statemachine_AirTemperature/statemachine_airtemp_control.h
        #statemachine_light_control.c
        #statemachine_light_control.h
        Statemachine_Water/Statemachine_Water/statemachine_watertemp_control.c
        Statemachine_Water/Statemachine_Water/statemachine_watertemp_control.h
        statemachines.h
        )

add_executable(Statemachines_X ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.8)
project(Statemachines_X)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.c
        statemachine_airquality_control.c
        statemachine_airquality_control.h
        statemachine_airtemp_control.c
        statemachine_airtemp_control.h
        statemachine_light_control.c
        statemachine_light_control.h
        statemachine_watertemp_control.c
        statemachine_watertemp_control.h)

add_executable(Statemachines_X ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.8)
project(Statemachines_X)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        #LightControl/StatemachineLightControl/main.c
        #LightControl/StatemachineLightControl/statemachine_light_control.h
        #LightControl/StatemachineLightControl/statemachine_light_control.c
        #main.c
        #AirQuality/Statemachine_AirQuality/main.c
        #AirQuality/Statemachine_AirQuality/statemachine_airquality_control.c
        #AirQuality/Statemachine_AirQuality/statemachine_airquality_control.h
        #AirTemperature/AirTemperature/statemachine_airtemp_control.c
        #AirTemperature/AirTemperature/statemachine_airtemp_control.h
        #statemachine_light_control.c
        #statemachine_light_control.h
        #WaterTemperature/WaterTemperature/statemachine_watertemp_control.c
        #WaterTemperature/WaterTemperature/statemachine_watertemp_control.h
        statemachines.h
        Technician/Structure/main.c
        Technician/Structure/technician_structure.c
        Technician/Structure/technician_structure.h
        )

add_executable(Statemachines_X ${SOURCE_FILES})
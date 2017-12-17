cmake_minimum_required(VERSION 3.8)
project(Schedules_X)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        get_schedules.c
        main.c
        schedules.c
        schedules.h
        message.h
        message.c
    )

add_executable(Schedules_X ${SOURCE_FILES})
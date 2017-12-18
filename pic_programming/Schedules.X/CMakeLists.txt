cmake_minimum_required(VERSION 3.8)
project(Schedules_X)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.c
        schedules.c
        schedules.h
        desiredValues.c
        desiredValues.h
        send_receive_messages.c
        send_receive_messages.h
        create_normal_message.c
    )

add_executable(Schedules_X ${SOURCE_FILES})
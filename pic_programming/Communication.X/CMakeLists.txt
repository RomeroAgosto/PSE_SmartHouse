cmake_minimum_required(VERSION 3.8)
project(communication)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c send_receive_messages.c send_receive_messages.h message.c message.h create_normal_message.c get_schedule_message.c schedules.h get_schedules.h)
add_executable(communication ${SOURCE_FILES})
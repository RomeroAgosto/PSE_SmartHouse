cmake_minimum_required(VERSION 3.8)
project(communication)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        StatemachineCommunication/main.c
        StatemachineCommunication/send_receive_messages.c
        StatemachineCommunication/send_receive_messages.h
        #StatemachineCommunication/create_normal_message.c
        #StatemachineCommunication/create_normal_message.h
        )

add_executable(communication ${SOURCE_FILES})
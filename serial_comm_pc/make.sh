#!/bin/bash

clear
g++ -Wall -I/usr/local/include -Llib/ \
src/regex/regexp.cpp \
src/main/somestuff.cpp \
src/main/serial_reception_handler.cpp \
src/main/controllerstate_query.cpp \
src/serial/serial.cpp \
-lboost_system -lboost_thread -lpthread -lRegExp -lpcre -lueye_api -lstdc++ -L/usr/lib64 -std=c++0x src/program.cpp -o bin/simple_interface


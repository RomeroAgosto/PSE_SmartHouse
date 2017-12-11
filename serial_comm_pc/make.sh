#!/bin/bash

clear
g++ -Wall -I/usr/local/include -Llib/ \
src/main/somestuff.cpp \
src/main/serial_reception_handler.cpp \
src/serial/serial.cpp \
src/telnet/socketserver.cpp \
src/main/websocket_reception_handler.cpp \
src/msgqueue/msgqueue.cpp \
src/main/websocket_write.cpp \
src/websocket/launch_server.cpp \
-lboost_system -lssl -lcrypto -lboost_thread -lboost_system -lboost_coroutine -lboost_context -lboost_filesystem -lpthread -lpcre -lstdc++ -L/usr/lib64 -std=c++0x src/program.cpp -o bin/simple_interface


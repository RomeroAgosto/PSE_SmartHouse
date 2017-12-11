#!/bin/bash

clear
g++ -Wall -I/usr/local/include -Llib/ \
src/regex/regexp.cpp \
src/main/somestuff.cpp \
src/main/serial_reception_handler.cpp \
src/serial/serial.cpp \
src/telnet/socketserver.cpp \
src/main/socket_reception_handler.cpp \
src/main/websocket_reception_handler.cpp \
src/msgqueue/msgqueue.cpp \
src/main/telnet_write.cpp \
src/main/websocket_write.cpp \
src/websocket/launch_server.cpp \
-lboost_system -lssl -lcrypto -lboost_thread -lboost_system -lboost_coroutine -lboost_context -lboost_filesystem -lpthread -lRegExp -lpcre -lstdc++ -L/usr/lib64 -std=c++0x src/program.cpp -o bin/simple_interface


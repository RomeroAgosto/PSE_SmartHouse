#ifndef __WEBSOCKET_SERVER_H
#define __WEBSOCKET_SERVER_H

#include<pthread.h> //for threading , link with lpthread
#include <boost/thread.hpp>

#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf

#include "../serial/serial.h"
#include "client_ws.hpp"
#include "server_ws.hpp"

extern bool websocket_server_running;
extern boost::mutex *cl_mutex;
extern void websocket_reception_handler(boost::mutex*, std::string);
extern CallbackSerial* serial_w;

void launch_websocket_server(unsigned int, boost::mutex*);
void websocket_sendToAllClients(std::string);

#endif

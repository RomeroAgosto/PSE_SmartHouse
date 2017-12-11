#ifndef __SIMPLE_INTERFACE_H__
#define __SIMPLE_INTERFACE_H__ 

	#include <stdio.h>
	#include <stdlib.h>
	#include <iostream>
	#include <signal.h>
	#include <algorithm>
	#include <sys/ioctl.h>	//serial port native funcs
	#include <queue>
	#include <math.h>

	#include <boost/algorithm/string.hpp>
	#include <boost/lexical_cast.hpp>
	#include <boost/thread.hpp>

	#include <stddef.h>

	#include "serial/serial.h"
	#include "telnet/socketserver.h" 
	#include "websocket/launch_server.h" 
	#include "main/socket_reception_handler.h"
	#include "main/websocket_reception_handler.h"
	#include "msgqueue/msgqueue.h"

	using namespace std;


	#define STX '#'//0x02
	#define ETX '*'   //0x03


	extern void websocket_reception_handler(boost::mutex*, string);

	void sigint_handler(int);
	void launch_serial_recv(CallbackSerial*);

	extern bool killSignal;
	void serial1_received(const unsigned char*, unsigned int);
	extern void reset_recv1_buffer();

	void MessageReceived(char*);

	extern bool telnet_server_running;
  void received(const unsigned char*, unsigned int);
  void telnet_sendToAll(string);
  void websocket_sendToAll(string);
	extern void websocket_sendToAllClients(string);

	extern bool websocket_server_running;

	extern bool msgbuffer_thread_running;
	std::shared_ptr<std::vector<char>> processInputLine(string);

#endif

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

	using namespace std;


	#define STX '#'//0x02
	#define ETX '*'   //0x03


	void sigint_handler(int);
	void launch_serial_recv(CallbackSerial*);

	extern bool killSignal;
	void serial1_received(const unsigned char*, unsigned int);
	extern void reset_recv1_buffer();

	void MessageReceived(char*);

#endif

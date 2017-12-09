#ifndef __TELNET_RECEPTION_HANDLER_H__
#define __TELNET_RECEPTION_HANDLER_H__ 
	
	#include <stdio.h>
	#include <iostream>
	#include <queue>
	#include "../serial/serial.h"

	using namespace std;	

	extern queue<string> MSGBUFFER;	
	extern CallbackSerial* serial_w;
	void telnet_reception_handler(boost::mutex*, int, const char*, unsigned int);

#endif

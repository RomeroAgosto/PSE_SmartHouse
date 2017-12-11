#ifndef __TELNET_RECEPTION_HANDLER_H__
#define __TELNET_RECEPTION_HANDLER_H__ 
	
	#include <stdio.h>
	#include <iostream>
	#include <queue>
	#include "../serial/serial.h"

	using namespace std;	

	extern queue<string> MSGBUFFER;	
	extern CallbackSerial* serial_w;
	void websocket_reception_handler(boost::mutex*, string);

#endif

#ifndef __MSGQUEUE_H__
#define __MSGQUEUE_H__
	
	#include <stdio.h>
	#include <iostream>
	#include <queue>
	#include <boost/algorithm/string.hpp>
	#include <boost/lexical_cast.hpp>
	#include "../serial/serial.h"
	#include "../delay/delay_ms.h"
	#include "../telnet/socketserver.h"
	
	using namespace std;
	
	extern bool msgbuffer_thread_running;

	extern queue<string> MGSBUFFER;
	extern CallbackSerial* serial_w;

	void MsgQueue_BufferOut(boost::mutex*); 
	extern unsigned long MSGBUFFER_DELAYBETWEENMESSAGES;

	extern void telnet_sendToAll(string);
	extern std::shared_ptr<vector<char>> processInputLine(string);

#endif //__MSGQUEUE_H__

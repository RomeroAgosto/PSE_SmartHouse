#include "socket_reception_handler.h"

CallbackSerial* serial_w = nullptr;

void telnet_reception_handler(boost::mutex *cl_mutex, int socket_id, const char *data, unsigned int len) {
	cl_mutex->lock();
	if(serial_w==nullptr) {
		puts("TelnetReceptionHandler:  Error: serial_w is not defined yet.");
		return;
	}
	string inputline("");

	for(int i=0; i<len; i++) {
		inputline += data[i];	
	}

	MSGBUFFER.push(inputline);
	cl_mutex->unlock();
}

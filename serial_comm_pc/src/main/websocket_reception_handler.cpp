#include "socket_reception_handler.h"

void websocket_reception_handler(boost::mutex *cl_mutex, string message) {
	cl_mutex->lock();
	if(serial_w==nullptr) {
		puts("WebsocketReceptionHandler:  Error: serial_w is not defined yet.");
		return;
	}

	MSGBUFFER.push(message);
	cl_mutex->unlock();
}

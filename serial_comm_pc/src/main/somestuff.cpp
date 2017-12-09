#include "../header.h"

bool killSignal = false;

void sigint_handler(int s){
	killSignal = true;
}

void launch_serial_recv(CallbackSerial* s) {
	s->doRead();
}


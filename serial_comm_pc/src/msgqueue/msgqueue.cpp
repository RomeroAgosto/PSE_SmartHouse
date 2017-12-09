#include "msgqueue.h"

queue<string> MSGBUFFER;
unsigned long MSGBUFFER_DELAYBETWEENMESSAGES=100;


void MsgQueue_BufferOut(boost::mutex *mutex) {
	msgbuffer_thread_running=true;

	string s1; string s2;
  stringstream ss1; stringstream ss2;
	while(1) {
		s1=""; s2=""; ss1.str(""); ss2.str("");
		if(!MSGBUFFER.empty()) {
			mutex->lock();
			cout << "In queue (received through socketserver): " << MSGBUFFER.size() << " messages.\n";
			string message = MSGBUFFER.front();
			printf("Sending message to serial port: %s\n", message.c_str());
			serial_w->doWrite( (const unsigned char*) message.c_str(), message.length() );
			MSGBUFFER.pop();
			mutex->unlock();
			if(MSGBUFFER_DELAYBETWEENMESSAGES>0) {
				delay(MSGBUFFER_DELAYBETWEENMESSAGES);
			}
		}
	}
}

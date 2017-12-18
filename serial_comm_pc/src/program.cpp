#include "header.h"

bool telnet_server_running = false;
bool msgbuffer_thread_running = false;
boost::mutex mutex1;
CallbackSerial* serial_w = NULL;

int main(int argc, char* argv[]) {
  if(argc!=3) {
    cerr << "Usage: simple_interface <serialport> <baudrate>." << endl;
    return 1;
  }
 
  signal(SIGINT, sigint_handler);  

	try {
    cout << "[...] Websocket Server: Launching (listen: " << 8080 << ")...";
    cout.flush();
    boost::thread websocket_server(launch_websocket_server, 8080, &mutex1);  
    while( !websocket_server_running );
    cout << "\r[OK] Websocket Server: Launching (listen: " << 8080 << ")...          "<<endl;

 		cout << "[...] Serial1: Launching...";
		cout.flush();
    CallbackSerial serial1(argv[1], boost::lexical_cast<unsigned int>(argv[2]));
    serial1.setCallback(serial1_received);
		serial_w = &serial1;
 		boost::thread serial1_thread(launch_serial_recv, &serial1);
		while( !serial1.serial_running );
  	cout << "\r[OK] Serial1 (controller): Launching...                                         "<<endl;

    cout << "[...] Msg Buffer: Launching...";
    cout.flush();
    boost::thread msgBuffer(MsgQueue_BufferOut, &mutex1); 
    while( !msgbuffer_thread_running );
    cout << "\r[OK] Msg Buffer: Launching...                                         "<<endl;

		while(!killSignal) {
      if(serial1.errorStatus() || serial1.isOpen()==false) {
       	cerr<<"Error(1): serial port unexpectedly closed"<<endl;
        break;
			}
			
			boost::this_thread::sleep(boost::posix_time::microseconds(100000));
		}

			cout << "\nEnded execution." << endl;
			cout.flush();
			serial1.doClose();

	} catch (std::exception& e) {
		cout<<"\nException: "<<e.what()<<endl;
		cout.flush();
		exit(1);
	}

	cout.flush();
	exit(0);
	return 0;	
}


void MessageReceived(char* message) {
	printf("Removing STX and ETX characters from the message...\n");
	unsigned int i=0;
	for(i=0; message[i]!='*' && message[i]!='\0'; i++) {
		message[i]=message[i+1];
		if(message[i+1]=='*') message[i+1]='\0';	
	}

	printf("Sending to all socket clients: %s\n", message);
	websocket_sendToAll(message);
}


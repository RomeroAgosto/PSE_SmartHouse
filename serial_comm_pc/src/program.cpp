/* SOCKETSERVER TCP PORT: 30123 */

#include "header.h"

bool telnet_server_running = false;
bool msgbuffer_thread_running = false;
boost::mutex mutex1;

int main(int argc, char* argv[]) {
  if(argc!=3) {
    cerr << "Usage: simple_interface <serialport> <baudrate>." << endl;
    return 1;
  }
 
  signal(SIGINT, sigint_handler);  

	try {
    cout << "[...] Socket Server: Launching (listen: " << 30123 << ")...";
    cout.flush();
    boost::thread telnet_server(socketserver_launch, 30123, &mutex1);  
    while( !telnet_server_running );
    cout << "\r[OK] Socket Server: Launching (listen: " << 30123 << ")...          "<<endl;

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
	printf("Sending to all socket clients: %s\n", message);
	telnet_sendToAll(message);	
}


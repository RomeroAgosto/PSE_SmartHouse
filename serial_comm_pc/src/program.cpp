#include "header.h"


int main(int argc, char* argv[]) {
  if(argc!=3) {
    cerr << "Usage: simple_interface <serialport> <baudrate>." << endl;
    return 1;
  }
 
  signal(SIGINT, sigint_handler);  

	try {

 		cout << "[...]  Serial1: Launching...";
		cout.flush();
    CallbackSerial serial1(argv[1], boost::lexical_cast<unsigned int>(argv[2]));
    serial1.setCallback(serial1_received);
 		boost::thread serial1_thread(launch_serial_recv, &serial1);
		while( !serial1.serial_running );
  	cout << "\r[OK]  Serial1 (controller): Launching...                                         "<<endl;

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


int counter =0;
void MessageReceived(char* message) {

	printf(":: %s ::\n", message);
	
}

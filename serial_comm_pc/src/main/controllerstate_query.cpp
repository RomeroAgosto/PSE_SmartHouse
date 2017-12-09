#include "../header.h"

bool controllerstate_query_running = false;

void controllerstate_query(CallbackSerial *serial) {
	controllerstate_query_running = true;

	char query_arr[] = {0x01,0x03,0x00,0x17,0x00,0x02,0x74,0x0F};	
	string query_line(query_arr, 8);
	int query_line_len=query_line.length();

	while(1) {
		boost::this_thread::sleep(boost::posix_time::seconds(1));
		serial->doWrite( (const unsigned char*)query_line.c_str(), query_line_len );
		boost::this_thread::sleep(boost::posix_time::seconds(1));
	}

  cout << "Controller state query: Stopped." << std::endl;
	controllerstate_query_running = false;
}

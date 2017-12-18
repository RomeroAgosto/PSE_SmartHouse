#include "../header.h"

std::shared_ptr<vector<unsigned char>> current_read1(new vector<unsigned char>(5000));
int current_read1_len=0;

void serial1_received(const unsigned char *data, unsigned int len) {

		for(unsigned int i=0; i<len; i++) {
			current_read1->at(current_read1_len)=boost::lexical_cast<unsigned char>(data[i]);
			current_read1_len++;

			if(data[i] == STX) {
				reset_recv1_buffer();
				current_read1->at(0)=STX;
				current_read1_len++;
			}

			if(data[i] == ETX) {
				int k; char message[current_read1_len+1];
				for(k=0; k<current_read1_len; k++) {
					message[k] = current_read1->at(k);
				}
				message[current_read1_len-1] = '\0';
				MessageReceived(message);
				reset_recv1_buffer();
		}
	}	
}

void reset_recv1_buffer() {
	current_read1_len=0;
}


#include "../header.h"

void telnet_sendToAll(std::string  str) {
	tln_sendToAllClients((char*)str.c_str(), strlen(str.c_str()));
}



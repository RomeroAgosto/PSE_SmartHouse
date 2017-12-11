#include "../header.h"

void websocket_sendToAll(std::string str) {
	websocket_sendToAllClients(str);
}

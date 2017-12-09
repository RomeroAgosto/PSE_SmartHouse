#ifndef __SOCKET_SERVER_H
#define __SOCKET_SERVER_H

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>    //strlen
#include<stdlib.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<pthread.h> //for threading , link with lpthread
#include <boost/thread.hpp>
 
//the thread function
extern bool telnet_server_running;

int socketserver_launch(unsigned int, boost::mutex*); 
void *connection_handler(void *);
void tln_sendToAllClients(char* msg, unsigned int len); 

extern int AllClients[];
extern int nClients;
extern void telnet_reception_handler(boost::mutex*, int, const char*, unsigned int);

#endif //__SOCKET_SERVER_H

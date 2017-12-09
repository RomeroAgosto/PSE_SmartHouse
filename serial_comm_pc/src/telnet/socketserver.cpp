#include "socketserver.h"

int nClients = 0;
int AllClients[25];

boost::mutex *cl_mutex;

int socketserver_launch(unsigned int port, boost::mutex *mutex1)
{
		cl_mutex = mutex1;
	
    int socket_desc , client_sock , c;
    struct sockaddr_in server , client;
     
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("SocketServer:  Error: Could not create socket.");
    }
    //puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( port );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("SocketServer:  Error: Bind failed.");
        return 1;
    }
    //puts("bind done");
     
    //Listen
    listen(socket_desc , 3);
     
    //Accept and incoming connection
    //puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
     
     
    //Accept and incoming connection
    //puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
		pthread_t thread_id;
	
		telnet_server_running = true;

    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted");
         
        if( pthread_create( &thread_id , NULL ,  connection_handler , (void*) &client_sock ) < 0)
        {
            perror("could not create thread");
            return 1;
        }
         
        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( thread_id , NULL);
        puts("SocketServer: New connection.");
    }
     
    if (client_sock < 0)
    {
        perror("SocketServer:  Error: Accept failed.");
        return 1;
    }
     
    return 0;
}

void tln_sendToAllClients(char* msg, unsigned int len) {
	int sock;
	for(int i=0; i<nClients; i++) {
		sock = AllClients[i];
		write(sock, msg, strlen(msg));
	}	
}

/*
 * This will handle connection for each client
 * */
void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[2000];
    std::string auxstr;

    //Send some messages to the client
    auxstr = std::string("COMMLAYER: CONNECTED.\n");
		message = (char*)auxstr.c_str();
		AllClients[nClients]=sock; nClients++;
    write(sock , message , strlen(message));
     
    //Receive a message from client
    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
      //end of string marker
			client_message[read_size] = '\0';
		
			//Send the message back to client
    	//write(sock , client_message , strlen(client_message));
			telnet_reception_handler(cl_mutex, sock, client_message , strlen(client_message));		
		
		

			//clear the message buffer
			memset(client_message, 0, 2000);
    }
     
    if(read_size == 0)
    {
				for(int i=0; i<nClients; i++) {
					if(AllClients[i]==sock) {
						for(int j=i+1; j<nClients;j++) {
							AllClients[j-1] = AllClients[j];
						}
						nClients--;
						break;
					}
				} 
        puts("SocketServer: Client disconnected.");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("SocketServer:  Error: Recv failed.");
    }
         
    return 0;
} 

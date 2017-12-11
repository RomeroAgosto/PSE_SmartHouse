#include "launch_server.h"

using namespace std;

using WsServer = SimpleWeb::SocketServer<SimpleWeb::WS>;
using WsClient = SimpleWeb::SocketClient<SimpleWeb::WS>;

bool websocket_server_running = false;
WsServer websocket_server;
std::unordered_set<std::shared_ptr<SimpleWeb::SocketServerBase<boost::asio::basic_stream_socket<boost::asio::ip::tcp> >::Connection>, std::hash<std::shared_ptr<SimpleWeb::SocketServerBase<boost::asio::basic_stream_socket<boost::asio::ip::tcp> >::Connection> >, std::equal_to<std::shared_ptr<SimpleWeb::SocketServerBase<boost::asio::basic_stream_socket<boost::asio::ip::tcp> >::Connection> >, std::allocator<std::shared_ptr<SimpleWeb::SocketServerBase<boost::asio::basic_stream_socket<boost::asio::ip::tcp> >::Connection> > > ALLCONNECTIONS;


void launch_websocket_server(unsigned int port, boost::mutex *mutex1) {

	cl_mutex = mutex1;

  websocket_server.config.port = port;
  auto &interface_api = websocket_server.endpoint["^/interface_api/?$"];

  interface_api.on_message = [](shared_ptr<WsServer::Connection> connection, shared_ptr<WsServer::Message> message) {
    auto message_str = message->string();

    cout << "Server (websocket): Message received: \"" << message_str << "\" from " << connection.get() << endl;
		websocket_reception_handler(cl_mutex, message_str);
	
  };

  interface_api.on_open = [](shared_ptr<WsServer::Connection> connection) {
    cout << "Server (websocket): Opened connection " << connection.get() << endl;
		ALLCONNECTIONS=websocket_server.get_connections();
  };

  interface_api.on_close = [](shared_ptr<WsServer::Connection> connection, int status, const string & /*reason*/) {
    cout << "Server (websocket): Closed connection " << connection.get() << " with status code " << status << endl;
  };

  interface_api.on_error = [](shared_ptr<WsServer::Connection> connection, const SimpleWeb::error_code &ec) {
    cout << "Server (websocket): Error in connection " << connection.get() << ". "
         << "Error: " << ec << ", error message: " << ec.message() << endl;
  };

	websocket_server_running = true;
  websocket_server.start();

}

void websocket_sendToAllClients(std::string str) {
  auto send_stream = make_shared<WsServer::SendStream>();
  *send_stream << str;
	printf("\n 111 %s\n", str.c_str());

   // echo_all.get_connections() can also be used to solely receive connections on this endpoint
  for(auto &a_connection : ALLCONNECTIONS) {
printf("\nCONNECTIONFOUND!\n");
      a_connection->send(send_stream);
  }

}

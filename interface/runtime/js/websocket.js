var ws=new WebSocket("ws://localhost:8080/interface_api");

ws.onmessage = function(e){
   var server_message = e.data;
   console.log(server_message);
}

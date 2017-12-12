$(document).ready( function() {
	$('#connect_button').click(function() {

		socket=new WebSocket("ws://localhost:8080/interface_api");
		

	});


	socket.onopen = function() {
	};

	socket.onmessage = function(e){
		var server_message = e.data;
		console.log(server_message);
	}

});



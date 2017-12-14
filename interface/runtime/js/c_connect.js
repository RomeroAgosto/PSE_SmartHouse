$(document).ready( function() {
	$('#connect_button').click(function() {
		socket=new WebSocket("ws://localhost:8080/interface_api");
		$('.scrmsg').html("Connecting ...");

		socket.onopen = function() {
			$('#screen-dontclick-overlay').hide();
			$('#buttons-dontclick-overlay').hide();
			loadScreen('home');
		};

		socket.onclose = function() {
			loadScreen('index');
			$('.scrmsg').html("DISCONNECTED.");
			$('#screen-dontclick-overlay').show();
			$('#buttons-dontclick-overlay').show();
		}

		socket.onerror = function() {
			loadScreen('index');
			$('.scrmsg').html("DISCONNECTED.");
			$('#screen-dontclick-overlay').show();
			$('#buttons-dontclick-overlay').show();
		}

		socket.onmessage = function(e) {
			var server_message = e.data;
	$('.col3-up-heating-1 .status').html(server_message);	
		}

	});
});



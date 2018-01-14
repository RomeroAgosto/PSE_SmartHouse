<?php if($_POST['accesscode']=='4321'):?>

			socket=new WebSocket("ws://localhost:8080/interface_api");

			socket.onopen = function() {
				socket.send("<?php echo $_POST['message']; ?>");
				socket.send("<?php echo $_POST['message']; ?>");
				socket.close();
			};
		
<?php else: http_response_code(500); ?>
<?php endif; ?>

$(document).ready(function() {
	$('#btn-undo').click(function() {
			switch(current_screen.name) {
				case 'menu1':
					loadScreen('home');
					break;
				case 'help':
					loadScreen(previous_screen);
					break;
				default:
					//do nothing;
			}
	});
});

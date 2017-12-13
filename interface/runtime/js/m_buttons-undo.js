$(document).ready(function() {
	$('#btn-undo').click(function() {
			switch(current_screen.name) {
				case 'menu1':
				case 'help':
					loadScreen('home');
					break;
				default:
					//do nothing;
			}
	});
});

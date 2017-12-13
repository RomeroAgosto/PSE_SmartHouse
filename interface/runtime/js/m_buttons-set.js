$(document).ready(function() {
	$('#btn-set').click(function() {
			switch(current_screen.name) {
				case 'home':
					loadScreen('menu1');
					break;
				default:
					//do nothing;
			}
	});
});

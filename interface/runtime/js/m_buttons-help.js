$(document).ready(function() {
	$('#btn-help').click(function() {
			switch(current_screen.name) {
				case 'home':
					$('#screen-help').html('Home scr help here.');
					break;
				default:
					$('#screen-help').html('No help available for the current screen.');
			}
			loadScreen('help');
	});
});

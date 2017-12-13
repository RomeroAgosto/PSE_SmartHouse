function loadScreen(screen_name, parameters) {
	switch(screen_name) {
		case 'index':
			$('.screens').hide();
			$('#screen-index').show();
			current_screen.name="index";
			current_screen.has_unsaved_data=0;
			break;
		case 'home':
			$('.screens').hide();
			$('#screen-home').show();
			current_screen.name="home";
			current_screen.has_unsaved_data=0;
			break;
		case 'menu1':
			$('.screens').hide();
			$('#screen-menu1').show();
			current_screen.name="menu1";
			current_screen.has_unsaved_data=0;
			break;
		case 'help':
			$('.screens').hide();
			$('#screen-help').show();
			current_screen.name="help";
			current_screen.has_unsaved_data=0;
			break;
		default:
			alert("Invalid request. (a_loadscreen.js)");
	}	
}

$(document).ready(function() {
	loadScreen('index');
});

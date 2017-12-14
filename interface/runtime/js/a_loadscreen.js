function loadScreen(screen_name, parameters) {
	if(screen_name!=current_screen.name)
		previous_screen=current_screen.name;

	switch(screen_name) {
		case 'index':
			$('.screens').hide();
			$('#screen-index').show();
			current_screen.name="index";
			current_screen.has_unsaved_data=0;
			menu1_lockflag1 = false;
			break;
		case 'home':
			$('.screens').hide();
			$('#screen-home').show();
			current_screen.name="home";
			current_screen.has_unsaved_data=0;
			previous_screen = 'home';
			break;
		case 'menu1':
			$('.screens').hide();
			$('#screen-menu1').show();
			current_screen.name="menu1";
			current_screen.has_unsaved_data=0;
			menu1_lockflag1 = false;
			menu1_scheduleset_step=0;

			//reset col1
			$('#screen-menu1 .row .col1 .option').removeClass('option-selected');
			$('#screen-menu1 .row .col1 .option').removeClass('option-focused');
			$($('#screen-menu1 .row .col1 .option').get(0)).addClass('option-selected');
			$($('#screen-menu1 .row .col1 .option').get(0)).addClass('option-focused');

			//reset col2 
			$('#screen-menu1 .row .col2 .option').removeClass('option-selected');
			$('#screen-menu1 .row .col2 .option').removeClass('option-focused');
			$('#screen-menu1 .row .col2 .option').hide();
			$('#screen-menu1 .row .col2 .option-airquality').show();
			$($('#screen-menu1 .row .col2 .option-airquality').get(0)).addClass('option-selected');
			$($('#screen-menu1 .row .col2 .option-heating').get(0)).addClass('option-selected');
			$($('#screen-menu1 .row .col2 .option-lightcontrol').get(0)).addClass('option-selected');
			$($('#screen-menu1 .row .col2 .option-watertemperature').get(0)).addClass('option-selected');

			//todo: reset col3,4,etc
			$('#screen-menu1 .row .col3 .col3-up').hide();
			$('#screen-menu1 .row .col3 .col3-up-airquality-1').show();
			$('#screen-menu1 .row .col3 .col3-weekdays').hide();
			$('#screen-menu1 .row .col3 .col3-weekdays-airquality-1').show();
			$('#screen-menu1 .row .col3 .col3-schedules').hide();
	
			

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
	$('#screen-menu1 .col2 .option').hide();
	$('#screen-menu1 .col2 .option-airquality').show();
});

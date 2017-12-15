$(document).ready(function() {
	$('#btn-arrowup').click(function() {
			access_granted_counter=60;	
			switch(current_screen.name) {
				case 'menu1':
					if(menu1_lockflag1) return;
					var colnumber=$($('#screen-menu1 .row .col .option-focused').parent()).data('col');
					var fieldname=$($('#screen-menu1 .row .col .option-focused').get(0)).data('field');
					if(colnumber == 1) {
						var alloptions = $('#screen-menu1 .row .col' + colnumber + ' .option').get();
						var i=0; var current_selection = -1;
						for(i=0; i<alloptions.length; i++) {
							if($(alloptions[i]).hasClass('option-selected')) {
								current_selection = i;
								break;
							}
						}	

						$(alloptions[current_selection]).removeClass('option-selected');
						$(alloptions[current_selection]).removeClass('option-focused');
						if(current_selection>0) current_selection--;
						$(alloptions[current_selection]).addClass('option-selected');
						$(alloptions[current_selection]).addClass('option-focused');
						var field = $(alloptions[current_selection]).data('field');
						
						$('#screen-menu1 .row .col' + (colnumber+1) + ' .option').hide();
						$('#screen-menu1 .row .col' + (colnumber+1) + ' .option-' + field).show();

						$('#screen-menu1 .row .col3 .col3-up').hide();
						var alloptions2 = $('#screen-menu1 .row .col2 .option[data-field="' + field + '"]').get();
						var current_selection2 = -1;
						for(i=0; i<alloptions2.length; i++) {
							if($(alloptions2[i]).hasClass('option-selected')) {
								current_selection2 = i;
								break;
							}
						}	
						var field2 = $(alloptions2[current_selection2]).data('field');
						$('#screen-menu1 .row .col3 .col3-up-' + field2 + "-" + (current_selection2+1)).show();
						$('#screen-menu1 .row .col3 .col3-weekdays').hide();
						$('#screen-menu1 .row .col3 .col3-weekdays-' + field2 + "-" + (current_selection2+1)).show();
						$('#screen-menu1 .row .col3 .col3-weekdays .weekday').removeClass('weekday-selected');
						$('#screen-menu1 .row .col3 .col3-weekdays .weekday').removeClass('weekday-focused');
					} else if(colnumber == 2) {
						var alloptions = $('#screen-menu1 .row .col2 .option-' + fieldname).get();
						var i=0; var current_selection = -1;
						for(i=0; i<alloptions.length; i++) {
							if($(alloptions[i]).hasClass('option-selected')) {
								current_selection = i;
								break;
							}
						}	

						$(alloptions[current_selection]).removeClass('option-selected');
						$(alloptions[current_selection]).removeClass('option-focused');
						if(current_selection>0) current_selection--;
						$(alloptions[current_selection]).addClass('option-selected');
						$(alloptions[current_selection]).addClass('option-focused');
						var field2 = $(alloptions[current_selection]).data('field');
						$('#screen-menu1 .row .col3 .col3-up').hide();
						$('#screen-menu1 .row .col3 .col3-up-' + field2 + "-" + (current_selection+1)).show();
						$('#screen-menu1 .row .col3 .col3-weekdays').hide();
						$('#screen-menu1 .row .col3 .col3-weekdays-' + field2 + "-" + (current_selection+1)).show();
						$('#screen-menu1 .row .col3 .col3-weekdays .weekday').removeClass('weekday-selected');
						$('#screen-menu1 .row .col3 .col3-weekdays .weekday').removeClass('weekday-focused');
						
					} else {
						colnumber=$('#screen-menu1 .row .col .weekday-focused').parent().parent().data('col');
					}

	







					if(colnumber==3) {
						var current_selection2 = -1;
						var current_selection3 = -1; 
						var i;
						var fieldname3 = $($('#screen-menu1 .row .col3-weekdays .weekday-focused').get(0)).parent().data('field');
						var allopt2 = $('#screen-menu1 .row .col2 .option[data-field=' + fieldname3 + ']').get();
						for(i=0; i<allopt2.length; i++) {
							if( $(allopt2[i]).hasClass('option-selected') ) {
								current_selection2 = i;
								break;
							}
						}
						var alldays = $('#screen-menu1 .row .col3-weekdays-' + fieldname3 + '-' + (current_selection2+1) + ' .weekday').get();
						for(i=0; i<alldays.length; i++) {
							if($(alldays[i]).hasClass('weekday-focused')) {
								current_selection3 = i;
								break;
							}
						}

						var allsch = $('#screen-menu1 .row .col3-schedules-' + fieldname3 + '-' + (current_selection2+1) + '-' +(current_selection3+1) +' .schedule');
						var current_selection4 = -1;
						for(i=0; i<allsch.length; i++) {
							if($(allsch[i]).hasClass('schedule-selected')) {
								current_selection4=i;
								break;
							}
						}

						$('#screen-menu1 .row .col3-schedules .schedule').removeClass('schedule-selected');
						$('#screen-menu1 .row .col3-schedules .schedule').removeClass('schedule-focused');
						if(current_selection4>0) {
							current_selection4--;
							$(allsch[current_selection4]).addClass('schedule-selected');
							$(allsch[current_selection4]).addClass('schedule-focused');
						}
					} 


					break;
				default:
					//do nothing;
			}
	});
});

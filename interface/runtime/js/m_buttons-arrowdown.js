$(document).ready(function() {
	$('#btn-arrowdown').click(function() {
			switch(current_screen.name) {
				case 'menu1':
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
						if(current_selection<alloptions.length-1) current_selection++;
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
					}

					if(colnumber == 2) {
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
						if(current_selection<alloptions.length-1) current_selection++;
						$(alloptions[current_selection]).addClass('option-selected');
						$(alloptions[current_selection]).addClass('option-focused');
						var field2 = $(alloptions[current_selection]).data('field');
						$('#screen-menu1 .row .col3 .col3-up').hide();
						$('#screen-menu1 .row .col3 .col3-up-' + field2 + "-" + (current_selection+1)).show();
						$('#screen-menu1 .row .col3 .col3-weekdays').hide();
						$('#screen-menu1 .row .col3 .col3-weekdays-' + field2 + "-" + (current_selection+1)).show();
						$('#screen-menu1 .row .col3 .col3-weekdays .weekday').removeClass('weekday-selected');
						$('#screen-menu1 .row .col3 .col3-weekdays .weekday').removeClass('weekday-focused');
							
					}
					break;
				default:
					//do nothing;
			}
	});
});

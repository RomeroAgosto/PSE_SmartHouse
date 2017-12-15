$(document).ready(function() {
	$('#btn-undo').click(function() {
			access_granted_counter=60;	
			switch(current_screen.name) {
				case 'pin_request':
					loadScreen('home');
					break;
				case 'menu1':
					var colnumber=$($('#screen-menu1 .row .col .option-focused').parent()).data('col');
					var fieldname=$($('#screen-menu1 .row .col .option-focused').get(0)).data('field');
					if(colnumber==1) {
						loadScreen('home');
					} else if(colnumber==2) {
						$('#btn-arrowleft').click();
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

						for(i=0; i<(current_selection3+1); i++) {
							$('#btn-arrowleft').click();
							var j; for(j=0; j<1000; j++); //DELAY.
						}
					}

					break;
				case 'help':
					loadScreen(previous_screen);
					break;
				default:
					//do nothing;
			}
	});
});

$(document).ready(function() {
	$('#btn-arrowright').click(function() {
			switch(current_screen.name) {
				case 'menu1':
					var colnumber=$($('#screen-menu1 .row .col .option-focused').parent()).data('col');
					var fieldname=$($('#screen-menu1 .row .col .option-focused').get(0)).data('field');
					if(colnumber == 1) {
						$('#screen-menu1 .row .col1 .option-focused').removeClass('option-focused');
						$('#screen-menu1 .row .col2 .option-' + fieldname +'.option-selected').addClass('option-focused');
					} else if (colnumber==2) {
						var selected2 = $('#screen-menu1 .row .col2 .option-focused').get(0);
						var field2 = $(selected2).data('field');
						var alloptions2 = $('#screen-menu1 .row .col2 .option-' + field2).get();
						var current_selection2 = -1;
						for(i=0; i<alloptions2.length; i++) {
							if($(alloptions2[i]).hasClass('option-selected')) {
								current_selection2 = i;
								break;
							}
						}	
						$(selected2).removeClass('option-focused');
						
						$('#screen-menu1 .row .col3-weekdays-' + field2 + '-' + (current_selection2+1) + ' .weekday').removeClass('weekday-selected');
						$('#screen-menu1 .row .col3-weekdays-' + field2 + '-' + (current_selection2+1) + ' .weekday').removeClass('weekday-focused');
						$('#screen-menu1 .row .col3-weekdays-' + field2 + '-' + (current_selection2+1) + ' .weekday-1').addClass('weekday-selected');
						$('#screen-menu1 .row .col3-weekdays-' + field2 + '-' + (current_selection2+1) + ' .weekday-1').addClass('weekday-focused');
					} else {

alert(3);
					}



					break;
				default:
					//do nothing;
			}
	});
});

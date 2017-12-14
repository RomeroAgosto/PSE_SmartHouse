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
						if(field2=='airquality') return;
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


						$('#screen-menu1 .row .col3-schedules').hide();
						$('#screen-menu1 .row .col3-schedules-' + fieldname + '-' + (current_selection2+1) + '-1').show();

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

						if(current_selection3 < (alldays.length-1)) {

							$('#screen-menu1 .row .col3-schedules').hide();

							$(alldays[current_selection3]).removeClass('weekday-selected');
							$(alldays[current_selection3]).removeClass('weekday-focused');
							current_selection3++;
							$(alldays[current_selection3]).addClass('weekday-selected');
							$(alldays[current_selection3]).addClass('weekday-focused');

							$('#screen-menu1 .row .col3-schedules-' + fieldname3 + '-' + (current_selection2+1) + '-' + (current_selection3+1)).show();
						}
					} 


					break;
				default:
					//do nothing;
			}
	});
});

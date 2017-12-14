$(document).ready(function() {
	$('#btn-arrowleft').click(function() {
			switch(current_screen.name) {
				case 'menu1':
					if(menu1_lockflag1) return;
					var colnumber=$($('#screen-menu1 .row .col .option-focused').parent()).data('col');
					var fieldname=$($('#screen-menu1 .row .col .option-focused').get(0)).data('field');
					if(colnumber==1) {
						;
					} else if (colnumber==2) {
						var selected2 = $('#screen-menu1 .row .col2 .option-focused').get(0);
						var field2 = $(selected2).data('field');
						$('#screen-menu1 .row .col2 .option-focused').removeClass('option-focused');
						$('#screen-menu1 .row .col1 .option-' + fieldname +'.option-selected').addClass('option-focused');
						
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

						$('#screen-menu1 .row .col3-schedules').hide();
						if(current_selection3==0) {
							$('#screen-menu1 .row .col2 .option-selected[data-field=' + fieldname3 + ']').addClass('option-focused');
							$('#screen-menu1 .row .col3-weekdays .weekday').removeClass('weekday-focused');
							$('#screen-menu1 .row .col3-weekdays .weekday').removeClass('weekday-selected');
						} else {
							$(alldays[current_selection3]).removeClass('weekday-selected');
							$(alldays[current_selection3]).removeClass('weekday-focused');
							current_selection3--;
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

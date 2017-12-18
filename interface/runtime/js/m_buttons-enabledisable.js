$(document).ready(function() {
	$('#btn-enabledisable').click(function() {
			access_granted_counter=60;	
			switch(current_screen.name) {
				case 'menu1':
					var colnumber=$($('#screen-menu1 .row .col .option-focused').parent()).data('col');
					var fieldname=$($('#screen-menu1 .row .col .option-focused').get(0)).data('field');
					if(colnumber==1) {
						;
					} else if(colnumber==2) {
						var option=$($('#screen-menu1 .row .col .option-focused').get(0));
						var fieldname=$($('#screen-menu1 .row .col .option-focused').get(0)).data('field');
						if(fieldname!='airquality') {
							if( option.hasClass('option-disabled') ) {
								option.removeClass('option-disabled');
							} else {
								option.addClass('option-disabled');

								var current_selection2 = -1;
								var allopt2 = $('#screen-menu1 .row .col2 .option[data-field=' + option.data('field') + ']').get();
								for(i=0; i<allopt2.length; i++) {
									if( $(allopt2[i]).hasClass('option-selected') ) {
										current_selection2 = i;
										break;
									}
								}
								$('#screen-menu1 .col3-schedules-' + option.data('field') + "-" + (current_selection2+1) + '-1 .schedule').addClass('schedule-disabled');
								$('#screen-menu1 .col3-schedules-' + option.data('field') + "-" + (current_selection2+1) + '-2 .schedule').addClass('schedule-disabled');
								$('#screen-menu1 .col3-schedules-' + option.data('field') + "-" + (current_selection2+1) + '-3 .schedule').addClass('schedule-disabled');
								$('#screen-menu1 .col3-schedules-' + option.data('field') + "-" + (current_selection2+1) + '-4 .schedule').addClass('schedule-disabled');
								$('#screen-menu1 .col3-schedules-' + option.data('field') + "-" + (current_selection2+1) + '-5 .schedule').addClass('schedule-disabled');
								$('#screen-menu1 .col3-schedules-' + option.data('field') + "-" + (current_selection2+1) + '-6 .schedule').addClass('schedule-disabled');
								$('#screen-menu1 .col3-schedules-' + option.data('field') + "-" + (current_selection2+1) + '-7 .schedule').addClass('schedule-disabled');
								$('#screen-menu1 .col3-schedules-' + option.data('field') + "-" + (current_selection2+1) + '-1 .schedule').data('dirty','1');
								$('#screen-menu1 .col3-schedules-' + option.data('field') + "-" + (current_selection2+1) + '-2 .schedule').data('dirty','1');
								$('#screen-menu1 .col3-schedules-' + option.data('field') + "-" + (current_selection2+1) + '-3 .schedule').data('dirty','1');
								$('#screen-menu1 .col3-schedules-' + option.data('field') + "-" + (current_selection2+1) + '-4 .schedule').data('dirty','1');
								$('#screen-menu1 .col3-schedules-' + option.data('field') + "-" + (current_selection2+1) + '-5 .schedule').data('dirty','1');
								$('#screen-menu1 .col3-schedules-' + option.data('field') + "-" + (current_selection2+1) + '-6 .schedule').data('dirty','1');
								$('#screen-menu1 .col3-schedules-' + option.data('field') + "-" + (current_selection2+1) + '-7 .schedule').data('dirty','1');
							}
						}
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

						var allsch = $('#screen-menu1 .row .col3-schedules-' + fieldname3 + '-' + (current_selection2+1) + '-' +(current_selection3+1) +' .schedule').get();
						var current_selection4 = -1;
						for(i=0; i<allsch.length; i++) {
							if($(allsch[i]).hasClass('schedule-selected')) {
								current_selection4=i;
								break;
							}
						}

						if(current_selection4==-1) {
							if($(allsch[0]).hasClass('schedule-disabled')) {
								$(allsch).removeClass('schedule-disabled');
								$(allsch).data('dirty','1');
							} else {
								$(allsch).addClass('schedule-disabled');	
								$(allsch).data('dirty','1');
							}
						} else {
							if($(allsch[current_selection4]).hasClass('schedule-disabled')) {
			 					$(allsch[current_selection4]).removeClass('schedule-disabled');
								$(allsch[current_selection4]).data('dirty','1');
							}	else {
								$(allsch[current_selection4]).addClass('schedule-disabled');
								$(allsch[current_selection4]).data('dirty','1');
							}
						}
					}

					break;
				default:
					//do nothing;
			}
	});
});








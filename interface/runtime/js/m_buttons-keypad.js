$(document).ready(function() {
	$('#keypad td').click(function(e) {
			switch(current_screen.name) {
				case 'menu1':

					var colnumber=$($('#screen-menu1 .row .col .option-focused').parent()).data('col');
					var fieldname=$($('#screen-menu1 .row .col .option-focused').get(0)).data('field');
					if(colnumber == 1 || colnumber==2) {
						return;
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

						if(current_selection4==-1) return;

						switch(menu1_scheduleset_step) {
							case 1:
								var _input = $(allsch[current_selection4]).find('.start_time').html();
								var i; var current_position=-1;
								for(i=0; i<_input.length; i++) {
									if(_input.charAt(i)=='-') {
										current_position = i;
										break;
									}
								}
								if(current_position==-1) {
									menu1_waitingforkeyboardinput=0;
									return;
								}

								var new_html = _input.replace('-',$(e.target).html());
								$(allsch[current_selection4]).find('.start_time').html(new_html);

								menu1_waitingforkeyboardinput--;
								if(menu1_waitingforkeyboardinput==0) $('#btn-set').click();
								break;
							case 2:
								var _input = $(allsch[current_selection4]).find('.end_time').html();
								var i; var current_position=-1;
								for(i=0; i<_input.length; i++) {
									if(_input.charAt(i)=='-') {
										current_position = i;
										break;
									}
								}
								if(current_position==-1) {
									menu1_waitingforkeyboardinput=0;
									return;
								}

								var new_html = _input.replace('-',$(e.target).html());
								$(allsch[current_selection4]).find('.end_time').html(new_html);

								menu1_waitingforkeyboardinput--;
								if(menu1_waitingforkeyboardinput==0) $('#btn-set').click();
								break;

							case 3:
								var _input = $(allsch[current_selection4]).find('.desired_value').html();
								var i; var current_position=-1;
								for(i=0; i<_input.length; i++) {
									if(_input.charAt(i)=='-') {
										current_position = i;
										break;
									}
								}
								if(current_position==-1) {
									menu1_waitingforkeyboardinput=0;
									return;
								}

								var new_html = _input.replace('-',$(e.target).html());
								$(allsch[current_selection4]).find('.desired_value').html(new_html);

								menu1_waitingforkeyboardinput--;
								if(menu1_waitingforkeyboardinput==0) $('#btn-set').click();

								break;
						}



}


					break;
				default:
					//do nothing;
			}
	});
});

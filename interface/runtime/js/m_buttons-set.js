$(document).ready(function() {
	$('#btn-set').click(function() {
			switch(current_screen.name) {
				case 'home':
					loadScreen('menu1');
					break;
				case 'menu1':
					var colnumber=$($('#screen-menu1 .row .col .option-focused').parent()).data('col');
					var fieldname=$($('#screen-menu1 .row .col .option-focused').get(0)).data('field');
					if(colnumber == 1){
						return;
					} else if(colnumber==2) {
						$('#btn-arrowright').click();
					}else {
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

						if(!menu1_lockflag1) menu1_scheduleset_step=0;
						menu1_lockflag1=true;
						if(menu1_waitingforkeyboardinput>0) return;

						menu1_scheduleset_step++;
						switch(menu1_scheduleset_step) {
							case 1:
								menu1_waitingforkeyboardinput=4;
								$(allsch[current_selection4]).find('.start_time').html('--:--');

								break;
							case 2:
								menu1_waitingforkeyboardinput=4;
								$(allsch[current_selection4]).find('.end_time').html('--:--');
								break;

							case 3:
								if(fieldname3=='lightcontrol') { 
									$('#btn-set').click();
									return;
								}
								menu1_waitingforkeyboardinput=2;
								$(allsch[current_selection4]).find('.desired_value').html('--');
								break;
							case 4:
								menu1_lockflag1=false;
								//TODO: SendValues !
								break;
						}

					}

					break;
				default:
					//do nothing;
			}
	});
});

current_screen={"name":"index", "has_unsaved_data": 0, info_to_keep: {} };
previous_screen='home';
socket = new WebSocket('ws://localhost:0/');
menu1_lockflag1=false;
menu1_scheduleset_step=0;
menu1_waitingforkeyboardinput=0;

access_granted = false;
access_granted_counter=0;
access_pin = '1234';
access_pin_input = "";

connected = false;
nextmsg_willbe = null;
sending_schedules = false;

$(document).ready(function() {
	$('#screen-menu1 .col3-schedules .schedule').attr('data-dirty','0');
	$('#screen-menu1 .col2 .option').addClass('option-disabled');
	$($('#screen-menu1 .col2 .option').get(0)).removeClass('option-disabled');
	$($('#screen-menu1 .col2 .option').get(1)).removeClass('option-disabled');
	$($('#screen-menu1 .col2 .option').get(2)).removeClass('option-disabled');
	$($('#screen-menu1 .col2 .option').get(3)).removeClass('option-disabled');
	$('#screen-menu1 .col3 .schedule').addClass('schedule-disabled');
});

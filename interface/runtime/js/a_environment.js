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

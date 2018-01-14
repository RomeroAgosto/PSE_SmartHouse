function processStatusMsg(json_obj) {
	var i=0;

	// Water
	if( Number(json_obj.water_data.water_heater) > 0 )
		$($('#screen-home .col1 div span').get(0)).html('ON');
	else
		$($('#screen-home .col1 div span').get(0)).html(' ');

	$($('#screen-home .row-2 div').get(2)).find('span').html('Water Temp.: ' + Math.round(Number(json_obj.water_data.temp)) + ' ºC');
	$('#screen-menu1 .col3-up-watertemperature-1 span').html(Math.round(Number(json_obj.water_data.temp)) + ' ºC');

	// Light
	if( Number(json_obj.light_data[0].light_state) > 0 ) {
		$($($($('#screen-home .col2 .col2-row').get(1)).find('div').get(0)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col2 .col2-row').get(1)).find('div').get(0)).find('span').get(0)).html(' ');
	}
	if( Number(json_obj.light_data[1].light_state) > 0 ) {
		$($($($('#screen-home .col2 .col2-row').get(1)).find('div').get(1)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col2 .col2-row').get(1)).find('div').get(1)).find('span').get(0)).html(' ');
	}
	if( Number(json_obj.light_data[2].light_state) > 0 ) {
		$($($($('#screen-home .col2 .col2-row').get(2)).find('div').get(0)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col2 .col2-row').get(2)).find('div').get(0)).find('span').get(0)).html(' ');
	}
	if( Number(json_obj.light_data[3].light_state) > 0 ) {
		$($($($('#screen-home .col2 .col2-row').get(2)).find('div').get(1)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col2 .col2-row').get(2)).find('div').get(1)).find('span').get(0)).html(' ');
	}
	if( Number(json_obj.light_data[4].light_state) > 0 ) {
		$($($($('#screen-home .col2 .col2-row').get(3)).find('div').get(0)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col2 .col2-row').get(3)).find('div').get(0)).find('span').get(0)).html(' ');
	}
	if( Number(json_obj.light_data[5].light_state) > 0 ) {
		$($($($('#screen-home .col2 .col2-row').get(3)).find('div').get(1)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col2 .col2-row').get(3)).find('div').get(1)).find('span').get(0)).html(' ');
	}
	if( Number(json_obj.light_data[6].light_state) > 0 ) {
		$($($($('#screen-home .col2 .col2-row').get(4)).find('div').get(0)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col2 .col2-row').get(4)).find('div').get(0)).find('span').get(0)).html(' ');
	}
	if( Number(json_obj.light_data[7].light_state) > 0 ) {
		$($($($('#screen-home .col2 .col2-row').get(4)).find('div').get(1)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col2 .col2-row').get(4)).find('div').get(1)).find('span').get(0)).html(' ');
	}


	// Air quality
	if( Number(json_obj.air_quality.fan) > 0 ) {
		$($('#screen-home .col3 div span').get(0)).html('ON');
		$($('#screen-home .col3 div span').get(2)).html('ON');
		$($('#screen-home .col3 div span').get(4)).html('ON');
		$($('#screen-home .col3 div span').get(6)).html('ON');
	} else {
		$($('#screen-home .col3 div span').get(0)).html(' ');
		$($('#screen-home .col3 div span').get(2)).html(' ');
		$($('#screen-home .col3 div span').get(4)).html(' ');
		$($('#screen-home .col3 div span').get(6)).html(' ');
	}

	for(i=0; i<4; i++) {
		switch(json_obj.air_quality.rooms[i].air_quality_state) {
			case "1":
				$('#screen-menu1 .col3-up-airquality-' + (i+1) +' span').html("WARNING");
				$('#airquality-icon').show();
				break;
			case "2":
				$('#screen-menu1 .col3-up-airquality-' + (i+1) +' span').html("DANGER!");
				$('#airquality-icon').show();
				break;
			default:
				$('#screen-menu1 .col3-up-airquality-' + (i+1) +' span').html("OK");
				$('#airquality-icon').hide();
				break;
		}
	}

	// Air temperature
	if( Number(json_obj.air_temperature[0].air_heater) > 0 ) {
		$($($($('#screen-home .col4 .col4-row').get(1)).find('div').get(0)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col4 .col4-row').get(1)).find('div').get(0)).find('span').get(0)).html(' ');
	}
	if( Number(json_obj.air_temperature[1].air_heater) > 0 ) {
		$($($($('#screen-home .col4 .col4-row').get(1)).find('div').get(1)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col4 .col4-row').get(1)).find('div').get(1)).find('span').get(0)).html(' ');
	}
	if( Number(json_obj.air_temperature[2].air_heater) > 0 ) {
		$($($($('#screen-home .col4 .col4-row').get(2)).find('div').get(0)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col4 .col4-row').get(2)).find('div').get(0)).find('span').get(0)).html(' ');
	}
	if( Number(json_obj.air_temperature[3].air_heater) > 0 ) {
		$($($($('#screen-home .col4 .col4-row').get(2)).find('div').get(1)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col4 .col4-row').get(2)).find('div').get(1)).find('span').get(0)).html(' ');
	}
	if( Number(json_obj.air_temperature[4].air_heater) > 0 ) {
		$($($($('#screen-home .col4 .col4-row').get(3)).find('div').get(0)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col4 .col4-row').get(3)).find('div').get(0)).find('span').get(0)).html(' ');
	}
	if( Number(json_obj.air_temperature[5].air_heater) > 0 ) {
		$($($($('#screen-home .col4 .col4-row').get(3)).find('div').get(1)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col4 .col4-row').get(3)).find('div').get(1)).find('span').get(0)).html(' ');
	}
	if( Number(json_obj.air_temperature[6].air_heater) > 0 ) {
		$($($($('#screen-home .col4 .col4-row').get(4)).find('div').get(0)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col4 .col4-row').get(4)).find('div').get(0)).find('span').get(0)).html(' ');
	}
	if( Number(json_obj.air_temperature[7].air_heater) > 0 ) {
		$($($($('#screen-home .col4 .col4-row').get(4)).find('div').get(1)).find('span').get(0)).html('ON');
	} else {
		$($($($('#screen-home .col4 .col4-row').get(4)).find('div').get(1)).find('span').get(0)).html(' ');
	}
	for(i=0; i<8; i++) {
		$('#screen-menu1 .col3-up-heating-' + (i+1) + ' span').html(Math.round(Number(json_obj.air_temperature[i].air_temp)) + ' ºC');
	}

	nextmsg_willbe=null;

}


function sendAllDirtySchedules() {
	if(nextmsg_willbe == "status" || nextmsg_willbe == "log") return;
	if(!connected) return;
	sending_schedules = true;
	functionalities = ["watertemperature", "heating", "lightcontrol"];
	var i=0; var j=0; var k=0; var w=0;
	for (i=0; i<functionalities.length; i++) {
		n_rooms = $('#screen-menu1 .col2 .option[data-field=' + functionalities[i] + ']').length;
		for(j=1; j<n_rooms+1; j++) {
			for(k=1; k<8; k++) {
				for(w=1; w<4+1; w++) {
					sch = $('#screen-menu1 .col3-schedules-' + functionalities[i] + '-' + j + '-' + k + ' .schedule-' + w);
					if(sch.data('dirty')!="1") continue;
					start_time = $(sch.find('.start_time').get(0)).html();
					end_time = $(sch.find('.end_time').get(0)).html();
					if(functionalities[i]=="lightcontrol") desired_value=0; else desired_value = $(sch.find('.desired_value').get(0)).html();
					var enabled = sch.hasClass('schedule-disabled') ? 0 : 1;
					if(enabled==1) {
						enabled = $($('#screen-menu1 .col2 .option[data-field=' + functionalities[i] + ']').get(j-1)).hasClass('option-disabled') ? 0 : 1;
					}

					newmessage = "#+" + i + "" + (j-1) + "" + (k-1) + "" + (w-1) + "0" + Math.floor(desired_value/10) + "" + (desired_value%10) + "" + enabled + "" + start_time[0] + "" + start_time[1] + "" + start_time[3] + "" + start_time[4] + "" + end_time[0] + "" + end_time[1] + "" + end_time[3] + "" + end_time[4] + "*";


					socket.send(newmessage);
					sch.data('dirty','0');



				}
			}
		}
	}	
	sending_schedules=false;
}

function processLogMsg(str) {
	nextmsg_willbe=null;
	$.post("savelog.php", {"text": str});
}


$(document).ready( function() {
	$('#connect_button').click(function() {
		socket=new WebSocket("ws://localhost:8080/interface_api");
		$('.scrmsg').html("Connecting ...");

		socket.onopen = function() {
			$('#screen-dontclick-overlay').hide();
			$('#buttons-dontclick-overlay').hide();
			connected = true;
			sendCurrentTime();
			nextmsg_willbe = null;
			loadScreen('home');
		};

		socket.onclose = function() {
			loadScreen('index');
			$('.scrmsg').html("DISCONNECTED.");
			$('#screen-dontclick-overlay').show();
			$('#buttons-dontclick-overlay').show();
			connected = false;
		}

		socket.onerror = function() {
			loadScreen('index');
			$('.scrmsg').html("DISCONNECTED.");
			$('#screen-dontclick-overlay').show();
			$('#buttons-dontclick-overlay').show();
		}

		socket.onmessage = function(e) {
			var server_message = e.data;

				switch(nextmsg_willbe) {
					case "status":
						var json_obj = JSON.parse(server_message);
						processStatusMsg(json_obj);
						break;
					case "log":
						processLogMsg(server_message);
						break;
					default:
						console.log('unknown message type detected.');
				}

			nextmsg_willbe = null;
			console.log('next msg null');

		}

	});
});



function lockScreen_Timeout() {
	if(!access_granted || access_granted_counter==0) return;
	access_granted_counter--;
	if(access_granted_counter==0) {
		access_granted=false;
		loadScreen('home');
		$('#unlocked-icon').hide();
	}

}


$(document).ready(function() {
	updateTime();
	setInterval(updateTime, 50000)
	setInterval(lockScreen_Timeout, 1000)
	setInterval(updateDataFromPIC, 3000)
	setInterval(sendAllDirtySchedules, 5000)
	setInterval(requestLog, 60000000)
});

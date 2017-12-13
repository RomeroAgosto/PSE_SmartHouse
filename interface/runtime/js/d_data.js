function updateTime() {
	var now = new Date();
	var HH = now.getHours();
	var mm = now.getMinutes();
	if(HH<10) HH = "0"+HH;	
	if(mm<10) mm = "0"+mm;	
	$('#screen-home .time-area .time').html(HH + ":" + mm);
}

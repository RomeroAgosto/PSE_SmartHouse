function sendCurrentTime() {
	var now = new Date();
/*
    dformat = [d.getMonth()+1,
               d.getDate(),
               d.getFullYear()].join('/')+' '+
              [d.getHours(),
               d.getMinutes(),
               d.getSeconds()].join(':');
*/
	var msg = "#@" + String(now.getFullYear()) + ("0"+String(now.getMonth()+1)).slice(-2) + String(now.getDay()) + ("0"+String(now.getDate())).slice(-2); //%M%%M% %WD% %D%%D% %H%%H% %m%%m% %s%%s% *
	msg = msg + ("0"+String(now.getHours())).slice(-2) + ("0"+String(now.getMinutes())).slice(-2) + ("0"+String(now.getSeconds())).slice(-2) + "*";
	socket.send(msg);
	for(i=1; i<10000; i++) { ; }
	socket.send(msg);
}

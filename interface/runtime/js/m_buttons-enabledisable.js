$(document).ready(function() {
	$('#btn-enabledisable').click(function() {
			switch(current_screen.name) {
				case 'menu1':
					var colnumber=$($('#screen-menu1 .row .col .option-focused').parent()).data('col');
					if(colnumber==2) {
						var option=$($('#screen-menu1 .row .col .option-focused').get(0));
						var fieldname=$($('#screen-menu1 .row .col .option-focused').get(0)).data('field');
						if(fieldname!='airquality') {
							if( option.hasClass('option-disabled') ) {
								option.removeClass('option-disabled');
							} else {
								option.addClass('option-disabled');
							}
						}
					}
					break;
				default:
					//do nothing;
			}
	});
});

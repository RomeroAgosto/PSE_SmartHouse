$(document).ready(function() {
	$('#btn-arrowleft').click(function() {
			switch(current_screen.name) {
				case 'menu1':
					var colnumber=$($('#screen-menu1 .row .col .option-focused').parent()).data('col');
					var fieldname=$($('#screen-menu1 .row .col .option-focused').get(0)).data('field');
					if(colnumber == 2) {
						$('#screen-menu1 .row .col2 .option-focused').removeClass('option-focused');
						$('#screen-menu1 .row .col1 .option-' + fieldname +'.option-selected').addClass('option-focused');
					}
					break;
				default:
					//do nothing;
			}
	});
});

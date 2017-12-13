<html>
	<head>
		<link rel="stylesheet" type="text/css" href="runtime/plugins/bootstrap/css/bootstrap.min.css">
		<link rel="stylesheet" type="text/css" href="runtime/plugins/font-awesome/css/font-awesome.min.css">
		<link rel="stylesheet" type="text/css" href="runtime/css/main.css">
		<link rel="stylesheet" type="text/css" href="runtime/css/buttons.css">
		<link rel="stylesheet" type="text/css" href="runtime/css/screen.css">
		<link rel="stylesheet" type="text/css" href="runtime/css/screen-home.css">
		<link rel="stylesheet" type="text/css" href="runtime/css/screen-menu1.css">
		<script src="runtime/plugins/jquery/jquery-3.2.1.min.js"></script>
	</head>
	<body>
		<div class="container">
 			<div class="row">
				<div class="col-md-1"></div>
					<div class="col-md-10" id="controller">
						<div class="row" style="margin-top: 20px;">
							<div class="col-md-1"></div>
							<div class="col-md-10" id="screen">
								<?php include_once('screen.php'); ?>
							</div>
							<div class="col-md-1"></div>
						</div>
						<div class="row">
							<div class="col-md-1"></div>
							<div class="col-md-10" id="buttons-section">
								<?php include_once('buttons-section.php'); ?>
							</div>
							<div class="col-md-1"></div>
						</div>
					</div>
				</div>
			</div>
			<div class="col-md-1"></div>
		</div>
		<script type="text/javascript" src="runtime/js/a_environment.js"></script>
		<script type="text/javascript" src="runtime/js/a_loadscreen.js"></script>
		<script type="text/javascript" src="runtime/js/c_connect.js"></script>
		<script type="text/javascript" src="runtime/js/d_data.js"></script>
		<script type="text/javascript" src="runtime/js/j_periodic.js"></script>
		<script type="text/javascript" src="runtime/js/m_buttons-arrowup.js"></script>
		<script type="text/javascript" src="runtime/js/m_buttons-arrowdown.js"></script>   
		<script type="text/javascript" src="runtime/js/m_buttons-home.js"></script>    
		<script type="text/javascript" src="runtime/js/m_buttons-undo.js"></script>
		<script type="text/javascript" src="runtime/js/m_buttons-arrowleft.js"></script>   
		<script type="text/javascript" src="runtime/js/m_buttons-enabledisable.js"></script>  
		<script type="text/javascript" src="runtime/js/m_buttons-keypad.js"></script>
		<script type="text/javascript" src="runtime/js/m_buttons-arrowright.js"></script>  
		<script type="text/javascript" src="runtime/js/m_buttons-help.js"></script>
		<script type="text/javascript" src="runtime/js/m_buttons-set.js"></script>

		<?php if($_GET['s']=='debug'): ?>
			<script type="text/javascript">
				$(document).ready(function(){
					$('#buttons-dontclick-overlay').hide();
					$('#screen-dontclick-overlay').hide();
					loadScreen('home');
				});
			</script>
		<?php endif ?>
	</body>
</html>

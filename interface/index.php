<html>
	<head>
		<link rel="stylesheet" type="text/css" href="runtime/plugins/bootstrap/css/bootstrap.min.css">
		<link rel="stylesheet" type="text/css" href="runtime/plugins/font-awesome/css/font-awesome.min.css">
		<link rel="stylesheet" type="text/css" href="runtime/css/main.css">
		<link rel="stylesheet" type="text/css" href="runtime/css/buttons.css">
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
	</body>
</html>

<?php
	$my_file = 'log/log.txt';
	$handle = fopen($my_file, 'a') or die('Cannot open file:  '.$my_file);
	$data = "\n". $_POST['text'];
	fwrite($handle, $data."\n\n");
?>

#!/usr/bin/php
<?php
	$a = "\"phpinfo()\"";
	$string = "${a}";

	function y($m)
	{
		print "coucou\n";
		print $m;
		print "\n";
		return 1;
	}
	print preg_replace('/^(.*)/e', "y(\"\\1\")", $string);
?>

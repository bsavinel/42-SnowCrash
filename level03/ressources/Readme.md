Opening ~ user folder we found a executable name level03, this an executable
We try to use ghydra to see the source code of the executable
The programe do 'system("/usr/bin/env echo Exploit me")'
The path of echo is not absolute so we can add an executable in /var/tmp nem echo and add the path /var/tmp to the environement variable PATH
The executable created do the command getflag and because the executable was of the group flag03 he can exectute this command
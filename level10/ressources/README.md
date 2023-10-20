We can see at ~ an executable named ./level10 and a file named token (without perm to read).
This program writes in the console "sends file to host if you have access to it"
We can guess that we need a server that can receive the data. What else than netcat with the -l option

We know that the program need a file with permissions as parameter
So we created two scripts:
The script-1 is an infinite loop that overwriting the symbolic link with the token file (file without permission) and overwriting the same symbolic link with a file with full permissions.
The other script is calling the ./level10 with the symbolic link from the above script

When starting nc -l localhost 6969 + ./script-1.sh + ./script-2.sh together, we found the password to log as flag10 and run getflag.

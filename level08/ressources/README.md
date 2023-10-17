We can see a executable file and a file named token.
We don't have permissions to read token, but that's what we want ! So we are gonna use the executable to read it.
With Ghidra we can see in that the executable reads a file and print his content.
The problem is that there is a protection for files named "token", so we can't send our token file as parameter to read through it.
To fix it we just did a symbolic link to access the file with another name.

ln -sf /home/user/level08/token /var/tmp/truc

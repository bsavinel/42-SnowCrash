We see an executable named level07
We scp the file and we read it with ghidra and we saw the programe run this :

pcVar1 = getenv("LOGNAME");
asprintf(&local_1c,"/bin/echo %s ",pcVar1);
iVar2 = system(local_1c);

We can see that the program is reading the environment variable LOGNAME and is append-ing to the string "/bin/echo "
then this execute the program

So if we change the LOGNAME variable with "a;getflag" the program also execute getflag
the trick is to use the shell ";" to execute an other program

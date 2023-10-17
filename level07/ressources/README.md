We see an executable named level07
We scp the file and we read with ghidra
and we saw the programe run this

pcVar1 = getenv("LOGNAME");
asprintf(&local_1c,"/bin/echo %s ",pcVar1);
iVar2 = system(local_1c);

we see the program is reading the environment variable LOGNAME and is append-ing to the string "/bin/echo "
then this execute the program

so if we change the LOGNAME varriable with "a;getflag" the programe also execute getflag
the trick is to use the shell ";" to execute an other program 

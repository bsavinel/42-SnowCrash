We can see that we have again a perl file which is using an egrep command with the program argument.
We can see also that this parameter is tranformed by regex formulas:
	- all char from a to z will be in Uppercase
	- all spaces and the rest char after the space is replaced by ""
We want to insert a call to a script, so our script can only be named with uppercase character. We only have access to /var/tmp, so we have to use wildcards (*) to not use uppercase

All we have to do is to insert the right argument to execute the command.

curl localhost:4646?x='a"$(/*/*/SCRIPT)"'&y=rien

The command inside $() is a command substitution, it is executed and is remplaced bu the result.
In this case, we just need to execute our script, we don't need to use the result.


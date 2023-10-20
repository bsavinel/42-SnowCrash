We've been exploring the files of the base tree. We found a weird file called
"john" in /usr/sbin. The creator of this file is "flag00" We could have found it
with this command find -type f -exec ls -la {} ; 2> /dev/null | grep flag

We cat-ted john, and we've seen a string, we've tested this key as a password
for flag00 but it didn't work. We thought that this string was encrypted, we
thought about the most basic encryption method which is Cesar encryption. We
launched it on our string, and on [A - Z]+15 (ROT15) the string make more sense:
"nottoohardhere". We tested it, it worked.

During the first look for level00, we seen a weird password in the /etc/passwd

As we know the x on flag02:x:3002:3002::/home/flag/flag02:/bin/bash means that the password is hidden and hashed in SHA512 in the /etc/shadow and this file is protected.
But in the /etc/passwd file there is a line where the x is not here but the hashed passwd is in clear text. flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash

We tried it for "flag01" but it did'nt work. SO we looked into a way to decrypt it. We found the "john the ripper" algorythm wich uses brute force to find the password. This program gave us abcdefg. It worked !

We saw that a crontab is executing a script every two minutes. /var/mail/level05
We digged into the file, which is a script that is bash-ing a list of script files inside this folder /opt/openarenaserver/
We created a script file in this folder calling "getflag" with a redirection

echo >/opt/openarenaserver/script "getflag >/var/tmp/flag"

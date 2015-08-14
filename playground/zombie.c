#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main() {
  pid_t pid = fork();

  if (pid < 0) {
    perror("fork error");
    exit(1);
  } else if (pid == 0) {
    printf("this is child process\n");
    exit(0);
  } else {
    system("ps -o pid,ppid,state,command");
    printf("this is parent process\n");

    return 0;
  }
}

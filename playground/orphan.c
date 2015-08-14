#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid < 0) {
    perror("fork error");
    exit(1);
  }

  if (pid == 0) {
    printf("this is child process with pid:%d ppid:%d\n", getpid(), getppid());
    sleep(5);
    printf("this is child process with pid:%d ppid:%d\n", getpid(), getppid());
  } else {
    printf("this is parent process with pid:%d ppid:%d\n", getpid(), getppid());
    sleep(1);
  }

  return 0;
}

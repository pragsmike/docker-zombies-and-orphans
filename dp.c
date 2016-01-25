#include <stdio.h>

int main(int argc, char **argv)
{
  printf(    "which          PID     parent\n");
  fflush(stdout);
  if (fork() == 0) {
    if (fork() == 0) {
      sleep(1);
      printf("Grandchild  %8d %8d\n", getpid(), getppid());
    } else {
      printf("Child       %8d %8d\n", getpid(), getppid());
    }
  } else {
    printf(  "Root        %8d %8d\n", getpid(), getppid());
    sleep(1);
  }
}

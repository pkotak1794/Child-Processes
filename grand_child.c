#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
  pid_t pid_one = fork();
  pid_t pid_two = fork();

  if (pid_one < 0) {
    fprintf(stderr, "Fork Failed"); // error occured
    exit (-1); // process termination
  }
  else if (pid_one != 0 && pid_two != 0) {
    printf("Parent process is created, my ID is %d\n", getpid()); // starting parent process
    wait(NULL);
  } else if (pid_one == 0 && pid_two != 0) {
    printf("Child process is created, my ID is %d\n", getpid()); // starting child process
    wait(NULL);
  }

  else if (pid_one != 0 && pid_two == 0) {
    //pid_t gc = fork();
    printf("Grandchild process is created, my ID is %d\n", getpid()); // starting grandchild process
    execlp("/usr/bin/firefox", "firefox", NULL); // open firefox browser
    fprintf(stderr, "Mozilla Firefox could not be opened"); // error occured
    exit(-1); // process termination
  }
}

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int execute(char **args) {
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    if (execvp(args[0], args) == -1) perror("bob");
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("bob");
  } else {
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    
  }

  return 1;
}
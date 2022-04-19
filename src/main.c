#include <stdio.h>
#include <stdlib.h>

#include "builtin.h"
#include "parse.h"
#include "read.h"

int main(int argc, char **argv) {
  char *line;
  char **args;
  int status;
  
  do {
    printf("$ ");

    line = read_input();
    args = parse(line);
    status = exec_shell_builtin(args);

    free(line);
    free(args);
  } while (status);
  
  return EXIT_SUCCESS;
}
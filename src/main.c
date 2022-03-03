#include <stdio.h>
#include <stdlib.h>

#include "headers/builtin.h"
#include "headers/parse.h"
#include "headers/read.h"

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
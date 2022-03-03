#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int bob_cd(char **args);
int bob_help(char **args);
int bob_exit(char **args);

char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};

int (*builtin_func[]) (char **) = {
  &bob_cd,
  &bob_help,
  &bob_exit
};

int num_builtin_func() {
  return sizeof(builtin_str) / sizeof(char *);
}

int bob_cd(char **args) {
  if (args[1] == NULL) {
    fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("bob");
    }
  }
  return 1;
}

int bob_help(char **args) {
  printf("bob: the shell\n");
  printf("The following are built in functions:\n");

  for (int i = 0; i < num_builtin_func(); i++) {
    printf("%s  \n", builtin_str[i]);
  }

  return 1;
}

int bob_exit(char **args) {
  printf("Bye-bye!");
  return 0;
}

int exec_shell_builtin(char **args) {
  if (args[0] == NULL) {
    return 1;
  }

  for (int i = 0; i < num_builtin_func(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (builtin_func[i])(args);
    }
  }

  execute(args);
}
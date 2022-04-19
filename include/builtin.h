extern char *builtin_str[];
extern int (*builtin_func[]) (char **);

int num_builtin_func();
int bob_cd(char **args);
int bob_help(char **args);
int bob_exit(char **args);
int exec_shell_builtin(char **args);
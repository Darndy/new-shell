#ifndef DPSHELL_H
#define DPSHELL_H
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
char *location(char *arg);
char *hndl_path(char *arg);
/*char* location(const char *path, const char *arg);
char *hndl_path(const char *arg);*/
int make_pid(char *cmd, char **env, char **av);
#define MAX_CMD_LEN 256
#define MAX_ARG 256
#endif

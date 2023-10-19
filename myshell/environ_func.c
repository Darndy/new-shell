#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

extern char **environ;
void handleEnvCommand()
{
        char *used_env = *environ;

        while (used_env != NULL)
    {
        write(STDOUT_FILENO, used_env, strlen(used_env));
        write(STDOUT_FILENO, "\n", 1);
        used_env = *(environ++);
    }
}

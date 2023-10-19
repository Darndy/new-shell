#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * executeCommand - Execute a command in a child process
 * @command: The command to be executed
 * @args:argument
 *
 * This function forks a child process and uses execve to execute
 * the specified command in that child process.
 */
void executeCommand(char *command, char *args[])
{
        pid_t pid;

        pid = fork();

        if (pid == -1)
        {
                perror("fork failed");
                exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {

                int miraNum = execve(command, args, NULL);

                if (miraNum == -1)
                {
                        perror("execve failed");
                        exit(EXIT_FAILURE);
                }
                exit(EXIT_SUCCESS);
        }
        else
        {
                wait(NULL);
        }
}

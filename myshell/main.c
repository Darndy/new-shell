#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * main - The main function of the shell program
 *
 * This function enters into a loop to continuously read user input,
 * execute commands, and free allocated memory until the user decides to exit.
 *
 * Return: 0 upon successful execution.
 */
int main(void)
{
        char *input;
        char **args = NULL;
        int i;

        int commandError = 0;

        while (1)
        {
                displayPrompt();
                input = readInput();

                if (input == NULL)
                {
                        break;
                }
                programArg(input, &args);
                handleExitCommand(args[0]);
                if (args[0][0] == '/')
                {
                        executeCommand(args[0], args);
                }
                else if (strcmp(args[0], "env") == 0)
                {
                        handleEnvCommand();
                }
                else
                {
                        handleCommand(args[0], args);

                        if (commandError == 1)
                        {
                                executeCommand(args[0], args);
                        }
                }
                commandError = 0;

                free(input);

                for (i = 0; args[i] != NULL; i++)
                {
                        free(args[i]);
                }
                free(args);
        }

        return (0);
}

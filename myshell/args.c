#include <string.h>
#include <stdlib.h>
#include "shell.h"
#include <stdio.h>

/**
 * processArg - Process input string into an array of arguments
 * @input: The input string
 * @args: Pointer to a pointer to char that will hold the array of arguments
 *
 * This function processes the input string and dynamically allocates memory
 * for an array of arguments. It uses strtok to split the input into tokens.
 * Memory is allocated as needed, and the array is NULL-terminated.
 */
void programArg(char input, char **args)
{
        size_t num = 10;
        size_t i = 0;
        char *token;
        args = (char *)malloc(num * sizeof(char *));

        if (*args == NULL)
        {
                perror("malloc failed");
                exit(EXIT_FAILURE);
        }
        token = strtok(input, " \n");

        while (token != NULL)
        {
                (*args)[i++] = strdup(token);

                if (i == num)
                {
                        num *= 2;
                        args = (char *)malloc(num * sizeof(char *));

                        if (*args == NULL)
                        {
                                perror("malloc failed");
                                exit(EXIT_FAILURE);
                        }
                }
                token = strtok(NULL, " \n");
        }
        (*args)[i] = NULL;
}

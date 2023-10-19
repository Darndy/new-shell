#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * readInput - Read a line of input from the user
 *
 * This function reads a line of input from the user, displaying a prompt.
 *
 * Return: A pointer to the buffer containing the input string.
 * NULL is returned if an error occurs or if the user enters an empty line.
 */
char *readInput()
{
        size_t n = 10;
        char *buff = malloc(sizeof(char) * n);
        int i;

        if (getline(&buff, &n, stdin) == -1)
        {
                free(buff);
                return (NULL);
        }

        i = strlen(buff);

        if (buff[i - 1] == '\n')
        {
                buff[i - 1] = '\0';
        }

        return (buff);
}

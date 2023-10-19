#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include  "shell.h"

int commandError = 0;
void handleCommand(char *command, char *args[]) {
    char *path = getenv("PATH");
    char *pathCopy = strdup(path);
    char *dir = strtok(pathCopy, ":");
    char errorMessage[] = "Command not found: ";
    size_t messageLength = strlen(errorMessage);

    if (pathCopy == NULL)
    {
        perror("strdup failed");
        exit(EXIT_FAILURE);

    }

    while (dir != NULL) {
        char *fullPath = malloc(strlen(dir) + strlen(command) + 2);
        if (fullPath == NULL) {
            perror("malloc failed");
            free(pathCopy);
            exit(EXIT_FAILURE);
        }

        strcpy(fullPath, dir);
        strcat(fullPath, "/");
        strcat(fullPath, command);

        if (access(fullPath, X_OK) == 0) {
            executeCommand(fullPath, args);
            free(fullPath);
            free(pathCopy);
            return;

        }

        free(fullPath);
        dir = strtok(NULL, ":");
    }
    if (pathCopy != NULL)
    {
            free(pathCopy);
    }
    if (strcmp(command, "env") == 0)
    {
        handleEnvCommand();
        return;
    }

    write(STDERR_FILENO, errorMessage, messageLength);
    write(STDERR_FILENO, command, strlen(command));
    write(STDERR_FILENO, "\n", 1);

    commandError = 1;
}

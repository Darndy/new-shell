#include "dpshell.h"

char *location(char *arg)
{
	struct stat b;
    char *path = getenv("PATH");
    printf("%s\n", path);
    if (path == NULL)
    {
        perror("Error: PATH environment variable not set");
        return NULL;
    }

    char *delim = ":";
    char *pathtoken = strtok(path, delim);
    while (pathtoken != NULL)
    {
        char *filepath = malloc(sizeof(char) *(strlen(pathtoken) + strlen(arg) + 2));
        if (filepath == NULL)
        {
            perror("Error");
            return NULL; // Handle memory allocation failure
        }

        strcpy(filepath, pathtoken);
        strcat(filepath, "/");
        strcat(filepath, arg);
	

	strcat(filepath, "\0");
 printf("%s\n", filepath);
        if (stat(filepath, &b) == 0)
        {
            return filepath;
        }

        free(filepath);
        pathtoken = strtok(NULL, delim);
    }

    return NULL; // Handle case when the executable is not found in any path
}

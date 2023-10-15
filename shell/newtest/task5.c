#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (1)
    {
        printf("$ ");
        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            printf("\n");
            break;
        }
        else
        {
            char *args[] = {"/bin/sh", "-c", line, NULL};
            if (execve(args[0], args, NULL) == -1)
            {
                perror("Error");
            }
        }
    }
    free(line);
    return (0);
}

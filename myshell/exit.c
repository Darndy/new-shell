#include <stdlib.h>
#include <stdio.h>
#include "shell.h"
#include <string.h>

void handleExitCommand(char *command)
{
    if (strcmp(command, "exit") == 0)
    {
        exit(0);
    }


}

#include <stdio.h>
#include "dpshell.h"

int main(void) 
{
    char *buf = NULL;
    size_t size = 0;

    ssize_t read_char;
    while ((read_char = getline(&buf, &size, stdin)) != -1) {
        printf("%s\n", buf);
    }

    free(buf);

    return 0;
}


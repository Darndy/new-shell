#include <stdio.h>
#include "dpshell.h"

int main(void) {
    char *prmpt = "(dpshell)>$ ";
    char *buf = NULL;
    size_t size = 0;

    while (1) {
        printf("%s", prmpt);

        ssize_t chars_read = getline(&buf, &size, stdin);

        if (chars_read == -1) {
            perror("Error reading input");
            break;
        }

        // Process user input here

        printf("You entered: %s", buf);
    }

    // Free dynamically allocated memory
    free(buf);

    return 0;
}


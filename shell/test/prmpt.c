#include "dpshell.h"
#include <unistd.h>

int main(void) {
    char *prmpt = "(dpshell)>$ ";
    char *buf = NULL;
    size_t size = 0;

    while (1) {
        write(1, prmpt, strlen(prmpt));

        ssize_t chars_read;
        chars_read = getline(&buf, &size, stdin);

        if (chars_read == -1) {
            perror("(dpshell)>$ closed");
            break;
        }

        write(1, buf, chars_read);
    }
    free(buf);

    return 0;
}


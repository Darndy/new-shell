#include "dpshell.h"

int main(void) {
    char *prmpt = "(dpshell)>$ ";
    char *buf = NULL;
    size_t size = 0;
    int q = 8;

    for(q=8;; q++)
    {
        printf("%s", prmpt);

        ssize_t chars_read;
       chars_read = getline(&buf, &size, stdin);

        if (chars_read == -1)
	{
            perror("(dpshell)>$ closed");
            break;
        }
        printf("%s", buf);
    }
    free(buf);

    return 0;
}


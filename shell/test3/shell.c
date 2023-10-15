#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char *prmpt = "(dshell)>$ ";
    char *buffer, *dup_buff;
    size_t size = 0;
    ssize_t nums_char;
    const char *delim = " \n";
    int token_num = 0, i;

    while (1) {
        printf("%s", prmpt);
        nums_char = getline(&buffer, &size, stdin);

        if (nums_char == -1) {
            printf("(dshell)>$ exited..\n");
            free(buffer);
            return (-1);
        }

        dup_buff = malloc(sizeof(char) * nums_char);
        if (dup_buff == NULL) {
            perror("Failed to allocate memory\n");
            free(buffer);
            return (-1);
        }

        strcpy(dup_buff, buffer);
        char *token = strtok(buffer, delim);
        while (token != NULL) {
            token_num++;
            token = strtok(NULL, delim);
        }

        argv = malloc(sizeof(char *) * (token_num + 1));
        token_num = 0;
        token = strtok(dup_buff, delim);
        while (token != NULL) {
            argv[token_num] = malloc(strlen(token) + 1);
            strcpy(argv[token_num], token);
            printf("%s\n", argv[token_num]);
            token_num++;
            token = strtok(NULL, delim);
        }

        free(dup_buff);
        for (i = 0; i < token_num; i++) {
            free(argv[i]);
        }
        free(argv);
        free(buffer);
    }

    return 0;
}


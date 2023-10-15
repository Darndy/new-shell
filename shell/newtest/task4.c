#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

int main(int ac, char **av) {
    char input[MAX_COMMAND_LENGTH];

    (void)ac;
    for (;;) {
        const char *prompt = "MyShell> ";
        write(STDOUT_FILENO, prompt, strlen(prompt));

        if (fgets(input, sizeof(input), stdin) == NULL) {
            if (feof(stdin)) {
                write(STDOUT_FILENO, "\n", 1);
                exit(EXIT_SUCCESS);
            } else {
                perror("fgets");
                exit(EXIT_FAILURE);
            }
        }

        input[strcspn(input, "\n")] = '\0';

        char *arguments[MAX_ARGUMENTS];
        int arg_count = 0;

        char *token = strtok(input, " \t");

        while (token != NULL && arg_count < MAX_ARGUMENTS - 1) {
            arguments[arg_count++] = token;
            token = strtok(NULL, " \t");
        }

        arguments[arg_count] = NULL;

        if (arg_count > 0) {
            pid_t child_pid = fork();

            if (child_pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            }

            if (child_pid == 0) {
                char *envp[] = {NULL};
                char *program = arguments[0];

                if (execve(program, arguments, envp) == -1) {
                    perror(program);
                    exit(EXIT_FAILURE);
                }
                exit(EXIT_SUCCESS);
            }
        }
    }
    return 0;
}


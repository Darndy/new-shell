#include "dpshell.h"
/**
 *
 *
 */

int main(void) 
{
    int status, i = 0;
    char buffer[90];
    char *arg[2] = {NULL, NULL};
    pid_t child_id;
    char *env[] = {NULL}; // Example environment variable, adjust as needed

    printf("Enter a command: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Removing newline character from the input
    while (buffer[i]) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            break;
        }
        i++;
    }

    // Checking if there is a new child process
    child_id = fork();

    if (child_id < 0) {
        _printsting("Failed to fork");
        free(arg[0]); // Free allocated memory for arg[0]
        exit(1);
    } else if (child_id == 0) {
        if (execve(arg[0], arg, env) == -1) {
            _printsting("Invalid command");
            exit(1);
        }
    } else {
        wait(&status);
    }

    // Free allocated memory before exiting the program
    free(arg[0]);

    return 0;
}

void _printsting(const char *message) {
    printf("%s\n", message);
}


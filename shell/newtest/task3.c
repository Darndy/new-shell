#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h> // Include errno for error handling

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

int main(int ac, char **av) {
    char input[MAX_COMMAND_LENGTH];

    int commandNotFound = 0; // Variable to track if "No such file or directory" was printed
	
	(void)ac;
    for (;;) {
        // Display the prompt using write
        const char *prompt = "MyShell> ";
        write(STDOUT_FILENO, prompt, strlen(prompt));

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            if (feof(stdin)) {
                // Ctrl+D (EOF) encountered, exit gracefully
                write(STDOUT_FILENO, "\n", 1);
                exit(EXIT_SUCCESS);
            } else {
                // Error reading input
                perror("fgets");
                exit(EXIT_FAILURE);
            }
        }

        // Remove the trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Tokenize the input using strtok
        char *arguments[MAX_ARGUMENTS];
        int arg_count = 0;

        char *token = strtok(input, " \t"); // Tokenize by space and tab characters

        while (token != NULL && arg_count < MAX_ARGUMENTS - 1) {
            arguments[arg_count++] = token;
            token = strtok(NULL, " \t");
        }

        arguments[arg_count] = NULL; // Null-terminate the argument list

        // Execute the command using fork and execve
        if (arg_count > 0) {
            pid_t child_pid = fork();

            if (child_pid == -1) {
                // Fork failed
                perror("fork");
                exit(EXIT_FAILURE);
            }

            if (child_pid == 0) {
                // Child process: execute the command using execve
                char *envp[] = {NULL}; // You can customize the environment here if needed
		char *program = av[0];
		char **command = arguments;

                if (execve(arguments[0], arguments, envp) == -1) {
                    // If execve fails, check for "No such file or directory"
                        // Print a generic error message for other failures
		write(STDERR_FILENO, program, strlen(program));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "No such file or directory\n", 26);
                    exit(EXIT_FAILURE);
                }
                // Child process continues execution if execve succeeds
                exit(EXIT_SUCCESS);
}
}
    return 0;
}
}

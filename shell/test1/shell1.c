int make_pid(char *cmd, char **env, char **av)
{
    cmd[strcspn(cmd, "\n")] = '\0';
    if (strlen(cmd) > 0) {
        // Check if the command is /bin/ls -l, and skip executing it
        if (strcmp(cmd, "/bin/ls -l") == 0) {
            printf("Skipping ls -l command.\n");
            return 0;
        }
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork failed");
            free(cmd);
            return (-1);
        }
        if (pid == 0) {
            char *argv[MAX_ARG];
            char *token = strtok(cmd, " \t\n");
            int i = 0;

            while (token != NULL) {
                argv[i++] = token;
                token = strtok(NULL, " \t\n");
            }
            argv[i] = NULL;
            execve(argv[0], argv, env);
            write(STDOUT_FILENO, av[0], strlen(av[0]));
            write(STDOUT_FILENO, ": ", 2);
            perror("");
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
        }
    }

    return (0);
}

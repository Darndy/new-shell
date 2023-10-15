#include "dpshell.h"
/**
 *
 *
 */
int make_pid(char *cmd, char **env, char **av)
{
	char *path = location(cmd);
	printf("%s\n", path);

	cmd[strcspn(cmd, "\n")] = '\0';
	char error_message[] = "No such file or directory\n";
	if (strlen(cmd) > 0)
	{


		pid_t pid = fork();
		if (pid == -1) {
			char error_message[] = "fork failed\n";
			write(STDOUT_FILENO, error_message, strlen(error_message));
			free(cmd);
			return (-1);
		}
		if (pid == 0) {
			char *argv[MAX_ARG];
			char *token = strtok(cmd, " \t\n");
			int i = 0;

			while (token != NULL) {
				argv[i] = token;
				i++;
				token = strtok(NULL, " \t\n");
			}
			argv[i] = NULL;
			execve(path, argv, env);

		} else {
			wait(NULL);
		}
	}

	return (0);
}

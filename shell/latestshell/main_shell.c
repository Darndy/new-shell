#include "dpshell.h"
/**
 *
 *
 *
 */

int main(int ac, char **av, char **env)
{
    char cmd[MAX_CMD_LEN];

    (void)ac;
    while (1) 
    {
        if (isatty(STDIN_FILENO))
	    printf("$ ");
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            // End-of-file or error
            printf("\n");
            return 0;
        }
        make_pid(cmd, env, av);
	if (isatty(STDIN_FILENO) == 0)
		break;

    }
    return 0;
}

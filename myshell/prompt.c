#include <unistd.h>
#include "shell.h"

/**
 * displayPrompt - Display the shell prompt
 *
 * This function writes the shell prompt "#cisfun$ "
 * to the standard output (usually the terminal).
 */
void displayPrompt(void)
{
        char prompt[] = "#cisfun$ ";

        write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

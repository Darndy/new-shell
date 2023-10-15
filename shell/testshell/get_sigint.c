#include "holberton.h"

/**
 * get_sigint - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}

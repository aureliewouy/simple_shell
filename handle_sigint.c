#include "holberton.h"
/**
 * handle_sigint - manage SIGINT
 * @sig: a signal we receive
 *
 */

void handle_sigint(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}

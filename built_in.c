#include "holberton.h"

/**
 * built_in - implement the exit built-in, that exits the shell
 *
 * @av: the arguments which passed
 * @buffer: the buffer of the command.
 *
 * Return: 1 if print_env is not use
 */
int built_in(char **av, char *buffer)
{
	if (_strcmp(av[0], "exit") == 0)
	{
		free(buffer);
		free_grid(av);
		exit(0);
	}
	if (_strcmp(av[0], "env") == 0)
	{
		print_env();
		return (0);
	}
	return (1);
}

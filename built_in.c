#include "holberton.h"

/**
 * built_in - implement the exit built-in, that exits the shell
 *
 * @av: the arguments which passed
 * @env: the environment variable
 */
void built_in(char **av, char **env)
{
	if (_strcmp(av[0], "exit") == 0)
	{
		free_grid(av);
		exit(0);
	}
	if (_strcmp(av[0], "env") == 0)
		print_env(env);
}

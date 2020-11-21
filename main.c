#include "holberton.h"

/**
 * main - Write a UNIX command line interpreter
 * @argc: the size of the array of string
 * @argv: the pointer to the array of the strings
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	char *buffer = NULL;
	char *delim, *token;
	size_t bufsize = 0;
	int i;
	char **av;
	(void)argc;
	delim = " \n";

	/*shell runs in an infinite loop*/
	while (1)
	{
		i = 0;
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		if (getline(&buffer, &bufsize, stdin) == EOF)
			return (0);
		av = malloc(bufsize * sizeof(char *));
		token = strtok(buffer, delim);
		while (token != NULL)
		{
			av[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		av[i] = NULL;
		if (_strcmp("exit", av[0]) == 0)
		{
			free(av);
			exit(0);
		}
		av[0] = verify_path(av);
		create_child_pid(av, argv);
		buffer = NULL;
		i = 0;
		free(av);
	}
	return (0);
}

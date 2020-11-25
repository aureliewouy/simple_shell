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


	if (signal(SIGINT, handle_sigint) == SIG_ERR)
		perror("error:\n");
	/*shell runs in an infinite loop*/
	while (1)
	{
		i = 0;
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		if (getline(&buffer, &bufsize, stdin) == EOF)
			return (0);
		av = malloc(bufsize * sizeof(char *));
		token = strtok(buffer, delim);
		while (token != NULL)
		{
			av[i] = _strdup(token);
			token = strtok(NULL, delim);
			i++;
		}
		av[i] = NULL;
		built_in(av, environ, buffer);
		av[0] = verify_path(av);
		create_child_pid(av, argv);
		free(token);
		free(buffer);
		buffer = NULL;
		free_grid(av);
	}
	return (0);
}

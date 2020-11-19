#include "holberton.h"
/**
 * main - Write a UNIX command line interpreter.
 * @argc: The size of the array.
 * @argv: The pointer the array of the strings
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	char *buffer = NULL;
	char *delim;
	size_t bufsize = 0;
	char *token;
	int i;
	char *av[] = {"", NULL};
	(void)argc;
	delim = " \n";
	while (1)
	{
		i = 0;
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		if (getline(&buffer, &bufsize, stdin) == EOF)
			return (0);
		token = strtok(buffer, delim);/*split string with the delim*/
		while (token != NULL) /*gets another elements the string*/
		{
			av[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		av[i] = '\0';
		create_child_pid(av, argv);
		buffer = NULL;
		free(token);
	}
	return (0);
}


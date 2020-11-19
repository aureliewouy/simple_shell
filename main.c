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
	char *buffer;
	size_t bufsize = 1024;
	pid_t child_pid;
	char *token;
	char *av[] = {"", NULL};
	(void)argc;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		buffer = (char *)malloc(bufsize * sizeof(char));
		if (getline(&buffer, &bufsize, stdin) == EOF)
			return(0);
		token = strtok(buffer, "\n");
		av[0] = token;
		token = strtok(NULL, "\n");
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(argv[0]);
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(av[0], argv, NULL) == -1)
				perror(argv[0]);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}

#include "holberton.h"
/**
 * print_env - implement the env built-in, that prints tha current environment
 * @environ: environment variable
 * Return: 0 in success, otherwise 1
 */
int print_env(char **environ)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		print_string(environ[i]);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * print_string - prints each line of env char par char
 * @environ: environment variable from print_env
 * Return: void
 */
void print_string(char *environ)
{
	int i;

	for (i = 0; environ[i] != '\0'; i++)
	{
		write(STDOUT_FILENO, environ, i);
	}
}

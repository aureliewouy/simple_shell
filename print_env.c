#include "holberton.h"
/**
 * print_env - implement the env built-in, that prints tha current environment
 * Return: 0 in success, otherwise 1
 */
int print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

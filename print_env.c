#include "holberton.h"
/**
 * print_env - implement the env built-in, that prints tha current environment
 * @env: environment variable
 * Return: 0 in success, otherwise 1
 */
int print_env(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		print_string(env[i]);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * print_string - prints each line of env char par char
 * @env: environment variable from print_env
 * Return: void
 */
void print_string(char *env)
{
	int i;

	for (i = 0; env[i] != '\0'; i++)
		;
	write(STDOUT_FILENO, env, i);
}

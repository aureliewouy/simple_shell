#include "holberton.h"

/**
 * _getenv - gets an environment variable
 * get value after "=""
 * @name: name of the variable user enter
 *
 * Return: pointer to a string (value of the variable)
 */
char *_getenv(const char *name)
{
	char *environ_string;
	char *value = NULL;
	int i = 0;

	while (environ[i] != '\0')
	{
		/*from array to the chain of characters*/
		environ_string = _strdup(environ[i]);
		/*selects the part of the line before =*/
		value = strtok(environ_string, "=");
		/*compare two strings*/
		if (_strcmp(_strdup(name), value) == 0)
		{
			return (strtok(NULL, "="));
		}
		i++;
		/*environ[i] = environ_string;*/
		free(environ_string);
	}
	return (NULL);
}

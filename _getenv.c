#include "holberton.h"

/**
 * _getenv - gets an environment variable
 * get value after "=" (name = value)
 * @name: name of the variable from user's enter
 *
 * Return: pointer to a string (value of the variable)
 */
char *_getenv(char *name)
{
	int i = 0;
	int j;
	char *value = NULL;

	while (environ[i])
	{
		j = 0;
		/*compare the user's name and the names at the PATH char par char*/
		while (environ[i][j] == name[j] && name[j] != '\0')
			j++;

		if ((environ[i][j] == '=') && (name[j] == '\0'))
		{
			/*setting a pointer to the first char of the value*/
			value = strdup(environ[i] + j + 1);
			break;
		}
		i++;
	}
	return (value);
}

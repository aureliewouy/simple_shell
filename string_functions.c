#include "holberton.h"

/**
 * *_strdup - a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter.
 * @str: the string.
 *
 * Return: a pointer to a new string or NULL.
 */

char *_strdup(char *str)
{
	char *new_s;
	int size = 0;
	int i = 0;

	if (str == NULL)
		return (NULL);
	while (str[size])
		size++;
	new_s = malloc((size + 1) * sizeof(char));
	if (new_s == NULL)
		return (NULL);
	while (i < size)
	{
		new_s[i] = str[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

#include "holberton.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: character
 *
 * Return: a pointer to a new string which is a duplicate of the string
 */
char *_strdup(char *str)
{
	int i, j = 0;
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		j++;
	ptr = malloc(sizeof(char) * j + 1);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < j; i++)
		ptr[i] = str[i];
	ptr[j] = '\0';
	return (ptr);
}

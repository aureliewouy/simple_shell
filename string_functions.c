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
/**
 * _strlen - returns the lenght of a string
 * @s : the string that we will find the length
 *
 * Return: Always 0.
 */

int _strlen(char *s)
{
	int n = 0;

	while (s[n])
	{
		++n;
	}
	return (n);
}

/**
 * *_strcat - appends the src string to thr dest string
 * @dest : the destination string
 * @src : the source string
 *
 * Return: Always 0.
 */

char *_strcat(char *dest, char *src)
{

	int i;
	int dest_len = _strlen(dest);

	for (i = 0 ; src[i] != '\0' ; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * _strcmp - Compare two strings
 * @s1 : the destination string
 * @s2 : the source string
 *
 * Return: Always 0.
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

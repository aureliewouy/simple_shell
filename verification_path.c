#include "holberton.h"
/**
 * array_directory_path - create an array of the directories path's
 *
 * @path_folder: a pointer to the value string (name(PATH) = value)
 *
 * Return: a pointer to the array of the strings
 */
char **array_directory_path(char *path_folder[])
{
	char *folder;
	char *path;
	int i = 0;

	/*receive full path value*/
	path = _getenv("PATH");
	/*for path_folder*/
	path_folder = (char **)malloc(sizeof(char *) * 32);
	/*split the string till delimiter, point to the first elem*/
	folder = strtok(path, ":");
	/*receive all other's elem's of the value string*/
	while (folder != NULL)
	{
		path_folder[i] = _strdup(folder); /*store each folder at the array*/
		folder = strtok(NULL, ":"); /*till NULL*/
		i++;
	}
	/*the last elem of the array of the strings*/
	path_folder[i] = NULL;
	return (path_folder);
}

/**
 * verify_path - check if the user's command exist
 * at the directories at the PATH,
 * if yes: transforms to the full path, clear to shell (ex:/bin/ls)
 * @av: a double pointer to the user's command
 *
 * Return: a command to execute, clear to shell
 */
char *verify_path(char **av)
{
	char **folder_path;
	char **path_f;
	struct stat st;
	int i;
	int len_pf;

	/*check if the command exist*/
	if (stat(av[0], &st) == 0)
		return (av[0]);
	folder_path = (char **)malloc(sizeof(char *) * 32);
	/*create an array of the directories path's*/
	path_f = array_directory_path(folder_path);
	if (path_f == NULL)
	{
		free(folder_path);
		free_grid(path_f);
		return (NULL);
	}
	i = 0;
	/*go through all the directories of the PATH*/
	while (path_f[i])
	{
		len_pf = _strlen(path_f[i]);
		path_f[i] = realloc(path_f[i], len_pf + _strlen(av[0]) + 2);
		path_f[i] = _strcat(path_f[i], "/");
		path_f[i] = _strcat(path_f[i], av[0]);

		/*if the command exist, remplace by the path folder*/
		if (stat(path_f[i], &st) == 0)
		{
			av[0] = _strdup(path_f[i]);
			break;
		}
		i++;
	}
	free_grid(path_f);
	free(folder_path);
	return (av[0]);
}

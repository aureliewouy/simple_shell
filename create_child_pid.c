#include "holberton.h"
/**
 * create_child_pid - creates a child pid and execute a program
 * @av: the array of the command to execute
 * @argv: the name of the compilated program
 */
void create_child_pid(char **av, char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork(); /*create a child pid*/

	if (child_pid == -1)
	{
		perror(argv[0]);
		return;
	}
	if (child_pid == 0) /*exec the program*/
	{
		if (execve(av[0], av, environ) == -1)
		{
			perror(argv[0]);
		}
	}
	else
	{
		wait(&status);
	}
}

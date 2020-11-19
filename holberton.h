#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

/*basic shell*/
void create_child_pid(char **av, char **argv);
int print_env(char **environ);
void print_string(char *env);

/*string manipulation functions*/
char *_strdup(char *str);

#endif

<p align="center">
<img width="409" height="128" src="https://www.holbertonschool.com/holberton-logo.png">
</p>

# Simple Shell

The goal of this projet is to write **a simple UNIX command interpreter**. It is the last project of the first trimestre at Holberton School.

## Learning Objectives

At the end of this project, we are expected to be able to explain to anyone, whitout the help of Google :

### General

* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of ```bash main```
* How does the shell use the ```PATH``` to find the programs
* How to execute another program with the ```bash execve```system call
* How to suspend the execution of a process until one of its children terminates
* What is ```bash EOF``` / end-of-file?

## Requirements

### General

* The allowed editors for this project are: ```vi```, ```vim```, ```emacs```
* All the files will be compiled on Ubuntu 14.04 LTS
* The C programs and functions will be compiled with ```gcc 4.8.4 ``` using the flags ```-Wall```  ```-Werror``` ```-Wextra``` ```and -pedantic```
* A ```README.md```, at the root of the folder of the project is mandatory
* Our code is verified using the ```Betty style```. It is checked using betty-style.pl and betty-doc.pl
* The created shell should not have any memory leaks
* Is not allowed to use more than 5 functions per file
* All the header files are include guarded

## More Info

### List of allowed functions and system calls 
-   `access`  (man 2 access)
-   `chdir`  (man 2 chdir)
-   `close`  (man 2 close)
-   `closedir`  (man 3 closedir)
-   `execve`  (man 2 execve)
-   `exit`  (man 3 exit)
-   `_exit`  (man 2 _exit)
-   `fflush`  (man 3 fflush)
-   `fork`  (man 2 fork)
-   `free`  (man 3 free)
-   `getcwd`  (man 3 getcwd)
-   `getline`  (man 3 getline)
-   `isatty`  (man 3 isatty)
-   `kill`  (man 2 kill)
-   `malloc`  (man 3 malloc)
-   `open`  (man 2 open)
-   `opendir`  (man 3 opendir)
-   `perror`  (man 3 perror)
-   `read`  (man 2 read)
-   `readdir`  (man 3 readdir)
-   `signal`  (man 2 signal)
-   `stat`  (__xstat) (man 2 stat)
-   `lstat`  (__lxstat) (man 2 lstat)
-   `fstat`  (__fxstat) (man 2 fstat)
-   `strtok`  (man 3 strtok)
-   `wait`  (man 2 wait)
-   `waitpid`  (man 2 waitpid)
-   `wait3`  (man 2 wait3)
-   `wait4`  (man 2 wait4)
-   `write`  (man 2 write)

### Compilation

Our shell will be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
### Testing

Interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

Non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## Development, task by task

#### 0. README, man, AUTHORS

-   Write a  `README`
-   Write a  `man`  for your shell.
-   Write an  `AUTHORS`  file at the root of the repository, listing all individuals having contributed content to the repository.

#### 1. Betty would be proud

Write a beautiful code that passes the Betty checks

#### 2. Simple shell 0.1

Write a UNIX command line interpreter.

-   Usage:  `simple_shell`

In this first level, our shell should:

-   Display a prompt and wait for the user to type a command. A command line always ends with a new line.
-   The prompt is displayed again each time a command has been executed.
-   The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
-   The command lines are made only of one word. No arguments will be passed to programs.
-   If an executable cannot be found, print an error message and display the prompt again.
-   Handle errors.
-   You have to handle the end of file condition (`Ctrl+D`)

We dont have to:

-   use the  `PATH`
-   implement built-ins
-   handle special characters :  `"`,  `'`,  `` ` ``,  `\`,  `*`,  `&`,  `#`
-   be able to move the cursor
-   handle commands with arguments

#### 3. Simple shell 0.2  mandatory

Simple shell 0.1 +

-   Handle command lines with arguments

#### 4. Simple shell 0.3  mandatory

Simple shell 0.2 +

-   Handle the  `PATH`

#### 5. Simple shell 0.4  mandatory

Simple shell 0.3 +

-   Implement the  `exit`  built-in, that exits the shell
-   Usage:  `exit`
-   You dont have to handle any argument to the built-in  `exit`

#### 6. Simple shell 1.0  mandatory

Simple shell 0.4 +

-   Implement the  `env`  **built-in**, that prints the current environment

#### 7. What happens when you type ls -l in the shell  mandatory

Write a blog post describing step by step what happens when you type  `ls -l`  and hit Enter in a shell. Try to explain every step you know of, going in as much details as you can, give examples and draw diagrams when needed. You should merge your previous knowledge of the shell with the specifics of how it works under the hoods (including syscalls).

-   Have at least one picture, at the top of the blog post
-   Publish your blog post on Medium or LinkedIn
-   Share your blog post at least on LinkedIn
-   Only one blog post by team
-   The blog post must be done and published before the first deadline (it will be part of the manual review)
-   Please, remember that these blogs must be written in English to further your technical ability in a variety of settings

When done, please add all urls below (blog post, LinkedIn post, etc.)

## Authors

Natalia Ponsard (https://github.com/natpons)

Aurelie Cedia (https://github.com/aureliewouy)

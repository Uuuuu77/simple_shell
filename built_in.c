#include "shell.h"

/**
 * built_in - function executes exit command.
 * @cmd: input of list of commands
 * @str: input of user string
*/
void built_in(char **cmd, char *str)
{
	if (_strcmp(cmd[0], "exit") == 0)
	{
		free_malloc(cmd);
		free(str);
		exit(EXIT_SUCCESS);
	}
}

/**
 * print_env - func prints the environment.
 * @cmd: input commands
*/
void print_env(char **cmd)
{
	int j;

	for (j = 0; environ[j] != NULL; j++)
	{
		_puts(environ[j]);
		_putchar('\n');
	}
	free_malloc(cmd);
}

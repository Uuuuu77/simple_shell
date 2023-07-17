#include "shell.h"

/**
 * built_in - Entry point-> It executes exit command.
 * @cmd: input list of commands
 * @str: input user string
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
 * print_env - Entry point-> It prints the environment.
 * @cmd: input commands
*/
void print_env(char **cmd)
{
	int b;

	for (b = 0; environ[b] != NULL; b++)
	{
		_puts(environ[b]);
		_putchar('\n');
	}
	free_malloc(cmd);
}

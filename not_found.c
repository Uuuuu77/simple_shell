#include "shell.h"

/**
 * prompt - Entry point-> Prints the prompt message
*/
void prompt(void)
{
	signal(SIGINT, sigint_handler);
	if (isatty(STDIN_FILENO))
		_puts("($) ");
}

/**
 * cmd_not_found - Entry point-> It prints error statement when cmd not found.
 * @av: input arguments list
 * @counter: input commands counter
 * @cmd_list: input list of commands
 * @path: input path list
*/
void cmd_not_found(char **av, int counter, char **cmd_list, char **path)
{
	_puts_err(av[0]);
	_puts_err(": ");
	print_counter(counter);
	_puts_err(": ");
	_puts_err(cmd_list[0]);
	_puts_err(": not found");
	_putchar_err('\n');
	free_malloc(cmd_list);
	free_malloc(path);
}

/**
 * getline_err - Entry point-> It sets new line & exits when it return -1.
 * @user_input: input string entered by user
*/
void getline_err(char *user_input)
{
	if (isatty(STDIN_FILENO))
		_putchar('\n');
	free(user_input);
	exit(EXIT_SUCCESS);
}

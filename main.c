#include "shell.h"

/**
 * sigint_handler - func handles the SIGINT.
 * @sigint_code: input value of sigint
*/
void sigint_handler(int sigint_code)
{
	(void)sigint_code;
	_putchar('\n');
	_puts("$ ");
}

/**
 * main - function Display the prompt.
 * @ac: argument count
 * @av: pointer to list of arguments
 * Return: 0 (success)
*/
int main(int ac __attribute__((unused)), char **av)
{
	char *b, *cmnd, *user_input = NULL, **cmd_list, **path;
	ssize_t c_read;
	size_t n;
	int counter = 0;

	while (1)
	{
		prompt();
		c_read = getline(&user_input, &n, stdin);
		counter++;
		if (c_read == -1)
			getline_err(user_input);
		if (user_input[0] == '\n')
			continue;
		cmd_list = tokenize(user_input);
		if (cmd_list[0] == NULL)
		{
			free(cmd_list);
			continue;
		}
		built_in(cmd_list, user_input);
		if (_strcmp(cmd_list[0], "env") == 0)
		{
			print_env(cmd_list);
			continue;
		}
		b = _getenv("PATH");
		path = path_list(b, cmd_list[0]);
		cmnd = test_path(path, cmd_list);
		if (cmnd != NULL)
			execute(cmnd, cmd_list);
		else
		{
			cmd_not_found(av, counter, cmd_list, path);
			continue;
		}
		free_malloc(cmd_list);
		free_malloc(path);
	}
	return (0);
}

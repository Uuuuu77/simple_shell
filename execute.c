#include "shell.h"

/**
 * execute - function executes any valid command.
 * @cmd: input command path that is found
 * @av: input array of commands and flags
*/
void execute(char *cmd, char **av)
{
	pid_t child_pid;
	int status;

	if (cmd)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("./hsh");
			return;
		}
		else if (child_pid == 0)
			execve(cmd, av, environ);
		else
		{
			do {
				waitpid(child_pid, &stat, WUNTRACED);
			} while (!WIFEXITED(stat) && !WIFSIGNALED(status));
		}
	}
}

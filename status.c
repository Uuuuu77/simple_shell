#include "shell.h"

/**
 * test_path - Entry point-> It finds the path of a given command.
 * @paths: input array of strings of the paths
 * @cmd_list: input array of strings of command passed
 * Return: similar path (Success)
*/
char *test_path(char **paths, char **cmd_list)
{
	struct stat st;
	char *similar;
	int b;

	if (stat(cmd_list[0], &st) == 0)
	{
		similar = cmd_list[0];
		return (similar);
	}
	else
	{
		for (b = 0; paths[b] != NULL; b++)
		{
			if (stat(paths[b], &st) == 0)
			{
				similar = paths[b];
				return (similar);
			}
		}
	}
	return (NULL);
}

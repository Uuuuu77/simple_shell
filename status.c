#include "shell.h"

/**
 * test_path - function finds the path of an input command.
 * @paths: an array of strings of the paths
 * @cmd_list: an array of strings of command passed
 * Return: similar path if Successful
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

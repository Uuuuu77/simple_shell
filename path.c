#include "shell.h"

/**
 * path_list - Entry point-> So it gets the PATH and splits it.
 * @path: input path to split
 * @cmd: input command to test it's path
 * Return: array of strings of paths (Success)
*/
char **path_list(char *path, char *cmd)
{
	char **path_s = NULL;
	char *token, *cp_path, *delim = ":";
	int path_size = _strlen(path) + 1;
	int path_letters = word_count(path) + 1;
	int b = 0;

	cp_path = malloc(sizeof(cp_path) * path_size);
	_strcpy(cp_path, path);

	path_s = malloc(sizeof(path_s) * path_letters);

	token = strtok(cp_path, delim);
	while (token != NULL)
	{
		path_s[b] = malloc(sizeof(token) * (_strlen(token) + 2));
		_strcpy(path_s[b], token);
		_strcat(path_s[b], "/");
		_strcat(path_s[b], cmd);
		_strcat(path_s[b], "\0");
		token = strtok(NULL, delim);
		b++;
	}
	path_s[b] = NULL;
	free(cp_path);

	return (path_s);
}

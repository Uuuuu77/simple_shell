#include "shell.h"

/**
 * path_list - function gets the PATH and splits it.
 * @path: path to split
 * @cmd: input tests it's path
 * Return: array of strings of paths if successful
*/
char **path_list(char *path, char *cmd)
{
	char **path_s = NULL;
	char *tkn, *cp_path, *delim = ":";
	int path_size = _strlen(path) + 1;
	int path_letters = word_count(path) + 1;
	int b = 0;

	cp_path = malloc(sizeof(cp_path) * path_size);
	_strcpy(cp_path, path);

	path_s = malloc(sizeof(path_s) * path_letters);

	tkn = strtok(cp_path, delim);
	while (tkn != NULL)
	{
		path_s[b] = malloc(sizeof(tkn) * (_strlen(tkn) + 2));
		_strcpy(path_s[b], tkn);
		_strcat(path_s[b], "/");
		_strcat(path_s[b], cmd);
		_strcat(path_s[b], "\0");
		tkn = strtok(NULL, delim);
		b++;
	}
	path_s[b] = NULL;
	free(cp_path);

	return (path_s);
}

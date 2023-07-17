#include "shell.h"

/**
 * tokenize - Entry point-> It splits string by delimeter given
 * @str: input string to split
 * Return: array of strings (Success)
*/
char **tokenize(char *str)
{
	char **cmd_list = NULL;
	char *token;
	const char *delim = " \t\n";
	int b, letters = word_count(str);

	cmd_list = malloc(sizeof(cmd_list) * (letters + 1));
	if (!cmd_list)
		return (NULL);
	token = strtok(str, delim);
	for (b = 0; token != NULL; b++)
	{
		cmd_list[b] = malloc(sizeof(token) * (_strlen(token) + 1));
		_strcpy(cmd_list[b], token);
		token = strtok(NULL, delim);
	}
	cmd_list[b] = NULL;

	return (cmd_list);
}

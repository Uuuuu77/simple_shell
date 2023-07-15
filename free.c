#include "shell.h"

/**
 * free_malloc - Entry point-> It frees malloc allocated to array of strings.
 * @str: input array of strings
*/
void free_malloc(char **str)
{
	char **memory = str;

	if (!str)
		return;
	while (*str)
		free(*str++);

	free(memory);
}

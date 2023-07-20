#include "shell.h"

/**
 * _getenv - Entry point-> Gets the environment of a specified type.
 * @name: input name of the environment
 * Return: environment string
*/
char *_getenv(const char *name)
{
	size_t name_len = _strlen(name);
	char *en = NULL;
	int b = 0;

	while (environ[b])
	{
		if (!_strncmp(name, environ[b], name_len))
			en = environ[b] + name_len + 1;
		b++;
	}
	return (en);
}

/**
 * _putchar - Entry point-> Writes the character c to stdout.
 * @c: input character to print
 * Return 1 (Success), Otherwise -1 (Error)
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Entry point-> Prints string excluding terminating char.
 * @str: input string to print
 * Return: number of chars printed (Success)
*/
int _puts(const char *str)
{
	int b = 0, num = 0;

	if (str)
	{
		while (str[b] != '\0')
		{
			_putchar(str[b]);
			num += 1;
			b++;
		}
	}

	return (num);
}

/**
 * _puts_err - Entry point-> Prints a string to stderr.
 * @str: input string to print
 * Return: number of chars printed (Success)
*/
int _puts_err(const char *str)
{
	int b = 0, num = 0;

	if (str)
	{
		while (str[b] != '\0')
		{
			write(2, &str[b], 1);
			num += 1;
			b++;
		}
	}

	return (num);
}

/**
 * _strcmp - Entry point-> Compares two string.
 * @s1: input first string
 * @s2: input second string
 * Return: difference of s1 and s2 || 0 if equal (Success)
*/
int _strcmp(char *s1, char *s2)
{
	int b = 0;

	for (; s1[b] != '\0' && s2[b] != '\0' && s1[b] == s2[b]; b++)
		;
	if (s1[b] == s2[b])
		return (0);

	return (s1[b] - s2[b]);
}

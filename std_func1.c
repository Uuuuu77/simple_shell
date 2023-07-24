#include "shell.h"

/**
 * _strcat - Entry point-> It concatenates two string.
 * @dest: input first string
 * @src: input second string
 * Return: Concatenated string (Success)
*/
char *_strcat(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a++)
		;
	for (b = 0; src[b] != '\0'; b++)
	{
		dest[a] = src[b];
		a++;
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * _strcpy - Entry point-> Copies a string.
 * @src: input source of string pointer
 * @dest: input destination pointer
 * Return: destination (Success)
*/
char *_strcpy(char *dest, char *src)
{
	int b = 0;

	for (; src[b] != 0; b++)
		dest[b] = src[b];
	dest[b] = '\0';

	return (dest);
}

/**
 * _strlen - Entry point-> Finds the length of a string.
 * @str: input string to find length
 * Return: length (Success)
*/
int _strlen(const char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);
	while (*str)
	{
		len++;
		str++;
	}

	return (len);
}

/**
 * _strncmp - Entry point-> Compares two string for the first n bytes.
 * @str1: input first string
 * @str2: input second string
 * @n: input bytes to compare
 * Return: 0 if = || < OR > 0 if unequal (Success)
*/
int _strncmp(const char *str1, const char *str2, size_t n)
{
	int s1, s2;

	while (*str1 && *str2 && (*str1 == *str2) && n)
	{
		n--;
		str1++;
		str2++;
	}

	s1 = *str1 + '0';
	s2 = *str2 + '0';

	if (n == 0)
		return (0);

	return (s1 - s2);
}

/**
 * word_count - Entry point-> Counts number of words in s string.
 * @s: input string to count words from
 * Return: number of words in a string (Success)
*/
int word_count(char *s)
{
	int status = 0;
	int num = 0;

	while (*s)
	{
		if (*s == '\n' || *s == '\t' || *s == ' ' || *s == ':')
			status = 0;
		else if (status == 0)
		{
			status = 1;
			num++;
		}
		s++;
	}

	return (num);
}

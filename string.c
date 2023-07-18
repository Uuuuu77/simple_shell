#include "shell.h"

/**
 * _putchar_err - function writes character c to STDERR.
 * @c: character to print
 * Return: 1 (Success), otherwise -1 (Error)
*/
int _putchar_err(char c)
{
	return (write(2, &c, 1));
}

/**
 * print_counter - function Converts int to astring & prints to STDERR.
 * @num: input int to convert & print
*/
void print_counter(int num)
{
	unsigned int a, b = 1;
	unsigned int ab, ab1, ab2 = 1;

	ab1 = num;
	while (ab1 > 9)
	{
		ab1 = ab1 / 10;
		ab2 = ab2 * 10;
		b++;
	}
	for (a = 1; a <= b; a++)
	{
		ab = num / ab2;
		num = num % ab2;
		ab2 = ab2 / 10;
		_putchar_err(ab + '0');
	}
}

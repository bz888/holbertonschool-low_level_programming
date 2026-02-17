#include "main.h"

/**
 * print_rev - print the string s in reverse.
 * @s: string to be printed.
 */
void print_rev(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	while (i)
	{
		_putchar(s[i - 1]);
		i--;
	}

	_putchar('\n');
}


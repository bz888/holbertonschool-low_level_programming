#include "main.h"

/**
 * _puts - print the string s.
 * @s: string to be printed.
 */
void _puts(char *s)
{
	int i = 0;

	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}

	_putchar('\n');
}


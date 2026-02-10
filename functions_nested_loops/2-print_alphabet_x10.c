#include "main.h"

/**
 * print_alphabet_x10 - prints
 */
void print_alphabet_x10(void)
{
	char c;
	int line;

	for (line = 0; line < 10; line++)
	{
		for (c = 'a'; c <= 'z'; c++)
			_putchar(c);
		_putchar('\n');
	}



}


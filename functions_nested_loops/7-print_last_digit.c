#include "main.h"

/**
 *print_last_digit - does things
 *@n: int
 *
 * Return: int
 */
int print_last_digit(int n)
{
	int l = n % 10;

	if (l < 0)
		l = -l;
	_putchar('0' + l);
	return (l);
}


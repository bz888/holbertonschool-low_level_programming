#include "main.h"

/**
 * print_sign - prints
 * @n: character int
 *
 * Return: bool.
 */
int print_sign(int n)
{
	if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	_putchar('-');
	return (-1);
}


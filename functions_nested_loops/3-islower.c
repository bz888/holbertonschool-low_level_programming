#include "main.h"

/**
 * _islower - prints
 * @c: character (int)
 *
 * Return: 0 or 1.
 */
int _islower(int c)
{
	if (c < 'a' || c > 'z')
	{
		return (0);
	}
	return (1);
}


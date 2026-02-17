#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: converted integer, or 0 if no digits are found
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, res = 0, found = 0, d;

	while (s[i] && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		found = 1;
		d = s[i] - '0';
		if (sign == 1)
		{
			if (res > (INT_MAX - d) / 10)
				return (INT_MAX);
			res = res * 10 + d;
		}
		else
		{
			if (res < (INT_MIN + d) / 10)
				return (INT_MIN);
			res = res * 10 - d;
		}
		i++;
	}
	return (found ? res : 0);
}


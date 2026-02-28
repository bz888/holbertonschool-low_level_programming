#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to scan
 * @accept: characters to match
 *
 * Return: number of bytes in the initial segment of s
 *         which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i;

	while (*s)
	{
		i = 0;

		while (accept[i])
		{
			if (*s == accept[i])
				break;
			i++;
		}

		if (accept[i] == '\0')
			return (count);

		count++;
		s++;
	}

	return (count);
}


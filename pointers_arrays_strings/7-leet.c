#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encode
 *
 * Return: s
 */
char *leet(char *s)
{
	int i = 0, j;
	char in[] = "aAeEoOtTlL";
	char out[] = "4433007711";

	while (s[i])
	{
		j = 0;
		while (in[j])
		{
			if (s[i] == in[j])
				s[i] = out[j];
			j++;
		}
		i++;
	}

	return (s);
}


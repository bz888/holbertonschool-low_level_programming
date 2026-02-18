#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: destination buffer (must have enough space)
 * @src: string to append from
 * @n: max number of bytes to take from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (dest[i])
		i++;

	while (src[j] && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}


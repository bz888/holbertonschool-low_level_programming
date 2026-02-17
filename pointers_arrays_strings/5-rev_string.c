#include "main.h"

/**
 *  rev_string - reverse s.
 * @s: string to be reversed.
 */
void rev_string(char *s)
{
	int i = 0, j = 0;
	char r;

	while (s[i])
		i++;
	i--;

	while (j < i)
	{
		r = s[j];
		s[j] = s[i];
		s[i] = r;
		j++;
		i--;
	}
}


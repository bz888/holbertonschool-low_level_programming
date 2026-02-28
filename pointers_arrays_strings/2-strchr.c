/**
 * _strchr - locates a character in a string
 * @s: string to search
 * @c: character to find
 *
 * Return: pointer to first occurrence of c, or NULL
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);

		s++;
	}

	/* Important: must also check the null terminator */
	if (c == '\0')
		return (s);

	return (NULL);
}


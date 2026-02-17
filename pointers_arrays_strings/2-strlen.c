/**
 * _strlen - find length of a string.
 * @s: string to be measured.
 *
 * Return: int length of string s.
 */
int _strlen(char *s)
{
	int i = 0;
	
	while(s[i])
		i++;

	return (i);
}


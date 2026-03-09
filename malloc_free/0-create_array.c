#include <stdlib.h>

/**
 * create_array - create an array of chars.
 * @c: the char value within the array.
 * @size: the size of the array to create.
 *
 * Return: a pointer to the char array, otherwise NULL.
 */
char *create_array(unsigned int size, char c)
{
	char *result;
	size_t i;

	if (size == 0)
		return (NULL);

	result = malloc(size);
	if (result == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		result[i] = c;

	return (result);
}


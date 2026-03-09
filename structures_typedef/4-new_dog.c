#include "dog.h"
#include <stdlib.h>

char *_strdup(char *s);

/**
 * new_dog - create new dog.
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Return: pointer to created dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	char *temp;
	dog_t *result = malloc(sizeof(dog_t));

	if (!result)
		return (NULL);

	temp = _strdup(name);
	if (!temp)
	{
		free(result);
		return (NULL);
	}
	else
		(*result).name = temp;

	temp = _strdup(owner);
	if (!temp)
	{
		free((*result).name);
		free(result);
		return (NULL);
	}
	(*result).owner = temp;

	(*result).age = age;

	return (result);
}

/**
 * _strdup - create a copy of s
 * @s: the string to be copied
 *
 * Return: a pointer to the copy of s, otherwise NULL
 */
char *_strdup(char *s)
{
	char *result;
	size_t i, len = 0;

	if (!s)
		return (NULL);

	while (s[len])
		len++;

	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		result[i] = s[i];

	return (result);
}


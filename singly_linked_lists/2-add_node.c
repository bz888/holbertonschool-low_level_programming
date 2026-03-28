#include "lists.h"

size_t _strlen(const char *s);

/**
 * add_node - add note to beginning of list
 * @head: pointer to head pointer
 * @str: string to store
 *
 * Return: first element of the list
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *first = malloc(sizeof(list_t));

	if (!first)
		return (NULL);
	if (!head)
	{
		free(first);
		return (NULL);
	}

	if (!str)
	{
		first->str = NULL;
		first->len = 0;
	}
	else
	{
		first->str = strdup(str);
		if (!first->str)
		{
			free(first);
			return (NULL);
		}
		first->len = _strlen(str);
	}

	first->next = *head;
	*head = first;
	return (first);
}

/**
 * _strlen - find length of s
 * @s: string to be measured (not NULL)
 *
 * Return: length of string
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s && *s)
	{
		len++;
		s++;
	}
	return (len);
}


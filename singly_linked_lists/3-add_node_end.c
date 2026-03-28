#include "lists.h"
#include <stdlib.h>

/**
 * _strlen - finds length of a string
 * @s: string to be measured
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

/**
 * _create_node - creates a new node
 * @s: string value of node
 * @next: pointer to next node
 *
 * Return: created node, or NULL if it fails
 */
list_t *_create_node(const char *s, list_t *next)
{
	list_t *node;

	node = malloc(sizeof(list_t));
	if (!node)
		return (NULL);

	if (!s)
	{
		node->str = NULL;
		node->len = 0;
	}
	else
	{
		node->str = strdup(s);
		if (!node->str)
		{
			free(node);
			return (NULL);
		}
		node->len = _strlen(s);
	}

	node->next = next;

	return (node);
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer of the head of the list
 * @str: string to be added
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *temp;

	if (!head)
		return (NULL);

	new_node = _create_node(str, NULL);
	if (!new_node)
		return (NULL);

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	temp = *head;
	while (temp->next)
		temp = temp->next;

	temp->next = new_node;

	return (new_node);
}


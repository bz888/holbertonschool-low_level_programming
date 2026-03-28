#include "lists.h"

/**
 * insert_dnodeint_at_index - insert item at index
 * @h: pointer to pointer to head of list
 * @idx: index of item to be added
 * @n: node value
 *
 * Return: item at index
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int count = 0;
	dlistint_t *item, *head = *h;

	if (!h)
		return (NULL);

	item = malloc(sizeof(dlistint_t));
	if (!item)
		return (NULL);

	item->n = n;

	while (head && count != idx)
	{
		count++;
		head = head->next;
	}

	if (count == idx)
	{
		item->prev = head->prev;
		head->prev = item;
		item->next = head;
		return (item);
	}
	else
		return (NULL);
}


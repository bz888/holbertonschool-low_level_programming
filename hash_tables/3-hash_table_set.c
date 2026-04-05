#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - adds or updates an element in a hash table
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node, *cur;
	unsigned long int idx;
	char *val;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	cur = ht->array[idx];

	while (cur)
	{
		if (strcmp(cur->key, key) == 0)
		{
			val = strdup(value);
			if (val == NULL)
				return (0);
			free(cur->value);
			cur->value = val;
			return (1);
		}
		cur = cur->next;
	}

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);

	node->key = strdup(key);
	if (node->key == NULL)
		return (free(node), 0);

	node->value = strdup(value);
	if (node->value == NULL)
		return (free(node->key), free(node), 0);

	node->next = ht->array[idx];
	ht->array[idx] = node;

	return (1);
}


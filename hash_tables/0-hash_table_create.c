#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - create hash table
 * @size: size of table
 *
 * Return: pointer to hash table, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *result;
	unsigned long int i;

	result = malloc(sizeof(hash_table_t));
	if (!result)
		return (NULL);

	result->array = malloc(sizeof(hash_node_t *) * size);
	if (!result->array)
	{
		free(result);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		result->array[i] = NULL;

	result->size = size;

	return (result);
}


#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * ht_pair - creates new hash node
 * @key: key to store in node
 * @value: value to store in node
 * Return: ptr to created node, or NULL upon failure
 */
hash_node_t *ht_pair(const char *key, const char *value)
{
hash_node_t *new_node = malloc(sizeof(hash_node_t));
if (new_node == NULL)
return (NULL);

new_node->key = strdup(key);
new_node->value = strdup(value);
new_node->next = NULL;

/* check if strdup success */
if (new_node->key == NULL || new_node->value == NULL)
{
free(new_node->key);
free(new_node->value);
free(new_node);
return (NULL);
}

return (new_node);
}

/**
 * hash_table_set - function that adds an element to the hash table.
 * @ht: hashtable to have node added
 * @key: key in hash
 * @value: value of the node
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int idx = 0;
hash_node_t *new_node, *current;

if (ht == NULL || key == NULL || key[0] == '\0' || value == NULL)
return (0);

idx = key_index((const unsigned char *)key, ht->size);
current = ht->array[idx];

/* check if key already exists */
while (current)
{
if (strcmp(current->key, key) == 0)
{
free(current->value);
/* duplicate value if key exists */
current->value = strdup(value);
if (current->value)
return (1);
else
return (0);
}
current = current->next;
}

/* create new node if key does not exist */
new_node = ht_pair(key, value);
if (new_node == NULL)
return (0);

/* insert node at head */
new_node->next = ht->array[idx];
ht->array[idx] = new_node;

return (1);
}


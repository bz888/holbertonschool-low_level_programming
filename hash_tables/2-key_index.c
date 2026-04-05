#include "hash_tables.h"
#include <stdlib.h>

/**
 * key_index - function that gives you the index of a key.
 * @size: size of the array of the hash table
 * @key: key in hash table
 * Return: return index of key in hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
unsigned long int hash;

/* check if args are valid */
if (key == NULL || size == 0)
return (0);

hash = hash_djb2(key);
return (hash % size);
}


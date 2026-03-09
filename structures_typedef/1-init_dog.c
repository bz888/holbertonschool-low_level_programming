#include "dog.h"
#include <stdlib.h>

char *_strdup(char *s);

/**
 * init_dog - initializes a dog struct
 * @d: pointer to dog struct to be initialized
 * @name: name of dog
 * @age: age of dog
 * @owner: name of owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (!d)
		return;
	d->name = name;
	d->owner = owner;
	d->age = age;
}


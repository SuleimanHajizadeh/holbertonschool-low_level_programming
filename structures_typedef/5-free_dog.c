#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees memory allocated for a dog
 * @d: pointer to dog to free
 *
 * Description: Frees the memory allocated for the dog's name,
 * owner, and the struct itself. If d is NULL, nothing happens.
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}

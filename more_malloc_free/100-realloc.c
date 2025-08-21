#include <stdlib.h>
#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with malloc(old_size)
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes, of the new memory block
 *
 * Return: pointer to the reallocated memory block, or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *new_ptr;
    unsigned int i, min_size;

    /* Case 1: new_size == old_size, return ptr unchanged */
    if (new_size == old_size)
        return (ptr);

    /* Case 2: ptr is NULL, equivalent to malloc(new_size) */
    if (ptr == NULL)
        return (malloc(new_size));

    /* Case 3: new_size == 0 and ptr not NULL, equivalent to free(ptr) */
    if (new_size == 0 && ptr != NULL)
    {
        free(ptr);
        return (NULL);
    }

    /* Case 4: allocate new block */
    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return (NULL);

    /* Copy contents: up to min(old_size, new_size) */
    min_size = (old_size < new_size) ? old_size : new_size;
    for (i = 0; i < min_size; i++)
        new_ptr[i] = ((char *)ptr)[i];

    /* Free old memory */#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: size in bytes of allocated space for ptr
 * @new_size: new size in bytes of the new memory block
 *
 * Return: pointer to newly allocated memory, or NULL if fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *old_ptr;
	unsigned int i, min_size;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	old_ptr = ptr;
	min_size = (old_size < new_size) ? old_size : new_size;

	for (i = 0; i < min_size; i++)
		new_ptr[i] = old_ptr[i];

	free(ptr);
	return (new_ptr);
}

    free(ptr);

    return (new_ptr);
}

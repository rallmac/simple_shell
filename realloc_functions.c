#include "shell.h"

/**
 * _memcpy - Copies data from one memory location to another.
 * @newptr: Pointer to the destination memory location.
 * @ptr: Pointer to the source memory location.
 * @size: Number of bytes to copy.
 *
 * Return: None.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - Resizes the memory block pointed to by ptr.
 * @ptr: Pointer to the memory block to reallocate.
 * @old_size: Previous size of the memory block.
 * @new_size: New size of the memory block.
 *
 * Return: Pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - Resizes an array of pointers (double pointer).
 * @ptr: Pointer to the array of pointers to reallocate.
 * @old_size: Previous size of the array.
 * @new_size: New size of the array.
 *
 * Return: Pointer to the reallocated array of pointers.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}

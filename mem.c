#include "main.h"

/**
 * _bytecpy- copies n bytes from source to destination
 * @dest: the destination string
 * @src: the source string
 * @n: the number of bytes to copy
 * Return: dest
 */
char *_bytecpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * rea_lloc - memory reallocation for char
 * @d: pointer to an array of strings
 * Return: pointer to the reallocated mem
 */
char *rea_lloc(char *d)
{
	int k = 0;
	char *new_pointer;

	if (d == NULL)
		return (NULL);

	while (*(d + k) != '\0')
		k++;
	new_pointer = malloc(sizeof(char) * k + 1);
	if (new_pointer == NULL)
		return (NULL);
	k = 0;
	while (*(d + k) != '\0')
	{
		*(new_pointer + k) = *(d + k);
		k++;
	}
	*(new_pointer + k) = '\0';
	return (new_pointer);
}

/**
 * _realloc - reallocates a memory block.
 * @ptr: pointer to the memory previously allocated.
 * @o_size: size, in bytes, of the allocated space of ptr.
 * @n_size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if n_size == o_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(n_size));

	if (n_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (n_size == o_size)
		return (ptr);

	newptr = malloc(n_size);
	if (newptr == NULL)
		return (NULL);

	if (n_size < o_size)
		mem_cpy(newptr, ptr, n_size);
	else
		mem_cpy(newptr, ptr, o_size);

	free(ptr);
	return (newptr);
}

/**
 * mem_cpy - copies information between void pointers.
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 *
 * Return: no return.
 */
void mem_cpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

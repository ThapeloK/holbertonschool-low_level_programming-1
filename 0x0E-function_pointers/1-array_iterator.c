#include "function_pointers.h"

/**
 * array_iterator - do actions on each element of an array
 *
 * Return: Nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	for (i = 0; i < size; i++)
	{
		(*action)(array[i]);
	}
}

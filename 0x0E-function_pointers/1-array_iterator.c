#include "function_pointers.h"

/**
 * array_iterator - do actions on each element of an array
 * @array: array
 * @size: size
 * @action: a function
 * Return: Nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (!array || size <= 0 || !action)
		exit(1);
	for (i = 0; i < size; i++)
	{
		(*action)(array[i]);
	}
}

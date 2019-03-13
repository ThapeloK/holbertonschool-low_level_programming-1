#include "function_pointers.h"

/**
 * int_index - searches for an integer inside of an array
 * @array: array
 * @size: size of the array
 * @cmp: function
 * Return: the index of found array
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (!array || cmp)
		exit(1);
	if (size <= 0)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if ((*cmp)(array[i]))
			return (i);
	}
	return (-1);
}

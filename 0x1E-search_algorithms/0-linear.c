#include "search_algos.h"

/**
 * linear_search - Linear search
 * @array: Target array
 * @size: Size of the @array
 * @value: Value to be searched
 * Return: Index where @value is located
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (!array || size == 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		/* printf("%lu\n", i); */
		if (array[i] == value)
		{
			return (i);
		}
	}

	return (-1);
}

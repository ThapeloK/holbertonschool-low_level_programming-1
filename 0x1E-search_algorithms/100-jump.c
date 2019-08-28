#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Jump search
 * @array: Target array
 * @size: Size of the @array
 * @value: Value to be searched
 * Return: Index where @value is located
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i;
	size_t sq;

	if (!array || size == 0)
		return (-1);

	sq = sqrt(size);
	for (i = 0; i < size && array[i] < value; i += sq)
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);

	printf("Value found between indexes [%lu] and [%lu]\n", i - sq, i);

	for (i = i - sq; i < size && array[i] <= value; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}

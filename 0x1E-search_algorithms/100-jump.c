#include <math.h>
#include "search_algos.h"
#define min(X, Y) (((X) < (Y)) ? (X) : (Y))

/**
 * jump_search - Jump search
 * @array: Target array
 * @size: Size of the @array
 * @value: Value to be searched
 * Return: Index where @value is located
 */
int jump_search(int *array, size_t size, int value)
{
	size_t right = 0;
	size_t left = 0;
	size_t i;
	size_t sq;

	if (!array)
		return (-1);

	sq = sqrt(size);
	for (i = 0; i < size; i += sq)
	{
		if (array[i] >= value)
		{
			right = i;
			break;
		}
		left = i;
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
	}
	if (right == 0)
		right = i;
	printf("Value found between indexes [%lu] and [%lu]\n", left, right);
	if (right > size)
	{
		printf("Value checked array[%lu] = [%d]\n", left, array[left]);
		return (-1);
	}

	for (i = left; i <= right; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}

	return (-1);
}



int jump_search_2(int *array, size_t size, int value)
{
    size_t step = sqrt(size);

size_t prev = 0;
while (array[min(step, size)-1] < value)
{
printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
prev = step;
step += sqrt(size);
if (prev >= size)
	return -1;
}

while (array[prev] < value)
{
prev++;

if (prev == min(step, size))
	return -1;
}
if (array[prev] == value)
	    return prev;

return -1;
}

#include "search_algos.h"

/**
 * interpolation_search - Linear search
 * @array: Target array
 * @size: Size of the @array
 * @value: Value to be searched
 * Return: Index where @value is located
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low;
	size_t high;
	size_t pos;

	low = 0;
	high = size - 1;

	while (low <= high)
	{
		if (low == high)
		{
			if (array[high] == value)
				return (high);
			return (-1);
		}

		pos = low + (((double)(high - low) /
			      (array[high] - array[low])) * (value - array[low]));

		if (pos > size)
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			return (-1);
		}

		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return (pos);

		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}
	return (-1);
}

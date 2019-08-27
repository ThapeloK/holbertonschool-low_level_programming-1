#include "search_algos.h"

/**
 * printer - Prints an array
 * @array: Target array
 * @left: Left index of @array
 * @right: Right index of @array
 */
void printer(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");

	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i == right)
			printf("\n");
		else
			printf(", ");
	}
}


/**
 * binary_search_2 - Binary search
 * @array: Target array
 * @start: Start of the @array
 * @end: End of the @array
 * @value: Value to be searched
 * Return: Index where @value is located
 */
int binary_search_2(int *array, size_t start, size_t end,  int value)
{
	size_t right;
	size_t left;
	size_t mid;

	if (!array)
		return (-1);

	left = start;
	right = end - 1;
	mid = (left + right) / 2;
	while (1)
	{
		printer(array, left, right);

		if (array[mid] == value)
			return (mid);
		if (mid == 0 || mid == end - 1)
			return (-1);

		if (array[mid] > value)
			right = mid - 1;
		else
			left = mid + 1;

		mid = (right + left) / 2;
	}

	return (-1);
}

/**
 * exponential_search - Binary search
 * @array: Target array
 * @size: Size of the @array
 * @value: Value to be searched
 * Return: Index where @value is located
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t end;

	if (!array || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}
	end = bound + 1 > size ? size : bound + 1;
	printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, end - 1);
	return (binary_search_2(array, bound / 2,  end, value));
}

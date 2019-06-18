#include "sort.h"


/**
 * _memset - Creates an array with initialized values
 * @size: Size of the @array
 * Return: Array
 */
int *_memset(size_t size)
{
	int *arr = malloc(sizeof(int) * size);

	if (!arr)
		return (NULL);
	while (size--)
		arr[size - 1] = 0;
	return (arr);
}

/**
 * get_max - Finds max int in @arr
 * @arr: Array of ints
 * @size: Size of the @arr
 * Return: Array
 */
int get_max(int *arr, size_t size)
{
	int max = arr[0];
	size_t i = 0;

	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}


/**
 * counting_sort - Counting sort
 * @array: Array to be sorted
 * @size: Size of the @array
 * Return: Nothing.
 */
void counting_sort(int *array, size_t size)
{
	int *copy = NULL, *res = NULL;
	int max = 0;
	uint i = 0, j = 0;

	if (!array || size < 2)
		return;
	max = get_max(array, size);
	copy = _memset(max + 1);
	res = _memset(size);
	if (!copy || !res)
		return;
	i = 0, j = max + 1;
	while (i < size)
		++copy[array[i++]];
	i = 1;
	while (i < j)
		copy[i] += copy[i - 1],	i++;
	print_array(copy, max + 1), i = 0;
	while (i < size)
	{
		res[copy[array[i]] - 1] = array[i];
		copy[array[i]]--;
		i++;
	}
	i = 0;
	while (i < size)
		array[i] = res[i], i++;
	free(copy), free(res);
}

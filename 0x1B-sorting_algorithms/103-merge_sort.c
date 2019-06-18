#include "sort.h"

/**
 * merge - merge sort
 * @array: Array to be sorted
 * @size: Size of the array
 * @m: Middle index
 * Return: Nothing.
 */
void merge(int *array, int size, int m)
{
	int i, j, k;
	int *x = malloc(sizeof(int) * size);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, m);
	printf("[right]: ");
	print_array(array + m, size - m);
	for (i = 0, j = m, k = 0; k < size; k++)
	{
		x[k] = j == size              ? array[i++]
			: i == m              ? array[j++]
			: array[j] < array[i] ? array[j++]
			:                       array[i++];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = x[i];
	}
	printf("[Done]: ");
	print_array(x, size);
	free(x);
}


/**
 * merge_sort - merge sort
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	int m;

	if (!array || size < 2)
		return;
	m = size / 2;
	merge_sort(array, m);
	merge_sort(array + m,  size - m);
	merge(array, size, m);
}

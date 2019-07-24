#include "sort.h"

/**
 * swap - Swaps two numbers
 * @n1: First number
 * @n2: Second number
 * Return: Nothing
 */
void swap(int *n1, int *n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

/**
 * shell_sort - Shell sorting algorithm using Knuth's sequence
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	uint gap = 1, i, j;
	int temp;

	if (!array || size < 2)
		return;
	while ((gap * 3) + 1 < size)
	{
		gap = gap * 3 + 1;
	}
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}

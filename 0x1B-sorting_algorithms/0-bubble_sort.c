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
 * bubble_sort - Bubble sort
 * @array: Array need to be sorted
 * @size: Size of the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	uint i;
	uint j;

	if (!array)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}

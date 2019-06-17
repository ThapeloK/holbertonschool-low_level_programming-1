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
 * selection_sort - Selection sort
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	uint i;
	uint j;
	uint min = 0;

	if (!array || size == 0)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		swap(&array[i], &array[min]);
		if (i != min)
			print_array(array, size);
	}
}

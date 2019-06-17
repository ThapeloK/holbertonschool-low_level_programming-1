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
 * partition_lomuto_sort - quick sort
 * @array: Array
 * @low: low index
 * @high: high index
 * @size: Size of the array
 */
void partition_lomuto_sort(int *array, int low, int high, int size)
{
	int current_low = low;
	int current_high = high;
	int pivot;

	if (low >= high)
		return;

	pivot = array[high];
	while (current_low < current_high)
	{
		while (current_low < current_high && array[current_low] < pivot)
		{
			current_low++;
		}
		while (current_low < current_high && array[current_high] >= pivot)
		{
			current_high--;
		}
		if (current_low < current_high)
		{
			swap(&array[current_low], &array[current_high]);
			print_array(array, size);
		}
	}
	if (current_high < high)
	{
		swap(&array[current_high], &array[high]);
		print_array(array, size);
	}

	partition_lomuto_sort(array, low, current_high - 1, size);
	partition_lomuto_sort(array, current_high + 1, high, size);
}

/**
 * quick_sort - Quick sorting algorithm
 * @array: Array
 * @size: Size of the @array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	partition_lomuto_sort(array, 0, size - 1, size);
}

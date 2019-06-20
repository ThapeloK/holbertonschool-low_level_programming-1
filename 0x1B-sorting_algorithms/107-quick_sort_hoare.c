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
 * partition - Swaps two numbers
 * @arr: Array
 * @low: First number
 * @high: Second number
 * @size: Size of the @array
 * Return: Nothing
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i, j;

	for (i = low, j = high; ; i++, j--)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i > j)
			return (j);
		print_array(arr, size);
		swap(&arr[i], &arr[j]);
	}

}

/**
 * quickSort - Swaps two numbers
 * @arr: Array
 * @low: First number
 * @high: Second number
 * @size: Size of the @array
 * Return: Nothing
 */
void quickSort(int *arr, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high, size);
		quickSort(arr, low, pi, size);
		quickSort(arr, pi + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Quick sort Hoare
 * @array: Array
 * @size: Size of the @array
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}

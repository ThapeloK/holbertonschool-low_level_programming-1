#include "holberton.h"

/**
 * array_range -  creates an int array
 * @min: start
 * @max: end
 *
 * Return: int *
 */

int *array_range(int min, int max)
{
	int *arr, i, j;

	if (min > max)
		return (NULL);
	arr = malloc(sizeof(int) * (max - min + 1));
	if (!arr)
		return (NULL);
	for (i = 0, j = min; j <= max; i++, j++)
	{
		arr[i] = j;
	}
	return (arr);
}

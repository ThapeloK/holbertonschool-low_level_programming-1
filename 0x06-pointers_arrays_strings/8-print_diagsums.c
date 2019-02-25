#include "holberton.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of diagonals of a matrix
 * @a: multi dimensional array or matrix
 * @size: deminsion of a matrix
 *
 * Return: Nothing
 */

void print_diagsums(int *a, int size)
{
	int i, d1 = 0, d2 = 0;

	for (i = 0; i < size * size; i = i + 1 + size)
	{
		d1 += *(a + i);
	}
	for (i = size - 1; i < size * size - 1; i = i + size - 1)
	{
		d2 += *(a + i);
	}
	printf("%d, %d\n", d1, d2);
}

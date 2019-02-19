#include "holberton.h"
#include <stdio.h>

/**
* print_array - prints array
* @a: takes array
* @n: takes int
*
* Return: void
*/

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i == n - 1)
			printf("%i", a[i]);
		else
			printf("%i, ", a[i]);
	}
	putchar('\n');
}

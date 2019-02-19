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
	int i, len;

	len  = 0;
	while(*a != '\0')
		len++;
	if (n != len)
		n = len;
	for (i = 0; i < n ; i++)
	{
		if (i == n - 1)
			printf("%i\n", a[i]);
		else
			printf("%i, ", a[i]);
	}
}

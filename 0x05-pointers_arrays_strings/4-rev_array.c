#include "holberton.h"

/**
* _strlen - returns the length of the string
* @s: takes string
*
* Return: returns the length int
*/

int _strlen(char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

/**
* reverse_array - reverse array
* @a: takes array
* @n: number of elements of the array
*
* Return: void
*/

void reverse_array(int *a, int n)
{
	int i;
	int temp;

	n = n - 1;
	for (i = 0; i < n / 2; i++)
	{
		temp = a[i];
		a[i] = a[n - i];
		a[n - i] = temp;
	}
}

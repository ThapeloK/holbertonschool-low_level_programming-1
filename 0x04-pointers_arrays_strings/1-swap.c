#include "holberton.h"
/**
* swap_int - swaps two integers
* @a: takes int
* @b: takes int
*
* Return: void
*/

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

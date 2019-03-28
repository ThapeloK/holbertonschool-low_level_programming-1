#include "holberton.h"

/**
 * clear_bit - clears a bit in given position
 * @n: number
 * @index: index of a number
 * Return: 1 if success, 0 if failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if ((*n > 0 || *n == 0) && (index > 0 || (index == 0)))
	{
		*n = *n & ~(1 << index);
		return (1);
	}
	return (-1);
}

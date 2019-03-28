#include "holberton.h"

/**
 * set_bit - sets a bit in given position
 * @n: number
 * @index: index
 * Return: number with setted position
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if ((*n > 0 || *n == 0) && (index > 0 || (index == 0)))
	{
		*n = *n | (1 << index);
		return (1);
	}
	return (-1);
}

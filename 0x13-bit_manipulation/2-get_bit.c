#include "holberton.h"

/**
 * get_bit - gets the bit in index
 * @n: the number
 * @index: index number
 * Return: 1 or 0
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if ((long long)n < 0)
		return (-1);
	return ((n & (1 << index)) && 1);
}

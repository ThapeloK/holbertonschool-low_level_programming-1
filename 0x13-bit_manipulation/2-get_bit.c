#include "holberton.h"

/**
 * get_bit - gets the bit in index
 * @n: the number
 * @index: index number
 * Return: 1 or 0
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int m = 0;

	if ((n > 0 || n == 0) && (index > 0 || (index == 0)))
	{
		m = (n >> index & 1);
		return (m);
	}
	return (-1);
}

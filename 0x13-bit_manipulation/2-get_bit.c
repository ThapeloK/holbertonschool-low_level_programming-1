#include "holberton.h"

/**
 * get_bit - gets the bit in index
 * @n: the number
 * @index: index number
 * Return: 1 or 0
 */
int get_bit(unsigned long int n, unsigned int index)
{
	return (index > 63 ? -1 : n >> index & 1);
}

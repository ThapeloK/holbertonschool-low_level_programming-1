#include "holberton.h"

/**
 * get_endianness -
 * @n: number to be checked
 * @m: desired number
 * Return: number of bits you need to flip to get m from n
 */
int get_endianness(void)
{
	int x = 1;
	char *y = (char *)&x;

	return(*y + '0');
}

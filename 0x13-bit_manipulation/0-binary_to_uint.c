#include "holberton.h"

/**
 * binary_to_uint - converst binary to uint
 * @b: binary number
 * Return: converted uint
 */
unsigned int binary_to_uint(const char *b)
{
	uint num = 0, val = 1, len = 0;
	int  i;

	if (!b)
		return (0);
	while (b[len])
	{
		if ((b[len] != '0' && b[len] != '1'))
			return (0);
		len++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (b[i] == '1')
			num += val;
		val <<= 1;
	}
	return (num);
}

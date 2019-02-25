#include "holberton.h"

/**
 * _memset - fills memory with a constant type
 * @s: takes string
 * @b: constant
 * @n: number of postions to be filled up with
 *
 * Return: returns a pointer
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

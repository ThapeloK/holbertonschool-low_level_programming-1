#include "holberton.h"

/**
 * malloc_checked - malloc() with checking
 * @b: size in bytes
 *
 * Return: void
 */

void *malloc_checked(unsigned int b)
{
	void *s;

	s = malloc(b);
	if (!s)
		exit(98);
	return (s);
}

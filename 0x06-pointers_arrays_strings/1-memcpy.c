#include "holberton.h"

/**
 * _memcpy - copies n bytes from src
 * @dest: destination
 * @src: source
 * @n: number of postions to be filled up with
 *
 * Return: returns a pointer
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

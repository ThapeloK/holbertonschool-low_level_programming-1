#include "holberton.h"

/**
 * _calloc - calloc() implementation
 * @nmemb: number of elements of the array
 * @size: size of a element
 *
 * Return: void
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *s;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	s = malloc(sizeof(char) * nmemb * size);
	if (!s)
		return (NULL);
	for (i = 0; i < nmemb * size; i++)
	{
		s[i] = 0;
	}
	return (s);
}

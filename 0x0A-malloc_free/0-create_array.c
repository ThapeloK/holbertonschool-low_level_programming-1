#include "holberton.h"
#include <stdlib.h>

/**
 * create_array - creates an array with malloc()
 *
 * Return: returns a pointer to an array
 */
char *create_array(unsigned int size, char c)
{
	char *s;

	s = malloc(size);
	while(size--)
	{
		s[size] = c;
	}
	return (s);
}

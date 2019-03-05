#include "holberton.h"
#include <stdlib.h>

/**
 * create_array - creates an array with malloc()
 * @size: size of the array
 * @c: character for initialization
 *
 * Return: returns a pointer to an array
 */
char *create_array(unsigned int size, char c)
{
	char *s;
	unsigned int i;

	if (size == 0)
		return (NULL);
	s = malloc(size);
	if (s == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
				s[i] = c;
	s[i] = '\0';
	return (s);
}

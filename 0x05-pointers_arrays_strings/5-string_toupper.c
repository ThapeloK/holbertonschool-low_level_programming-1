#include "holberton.h"

/**
 * string_toupper - converts to uppercase
 * @a: string
 *
 * Return: returns pointer
 */

char *string_toupper(char *a)
{
	int i;

	i = 0;
	while (a[i])
	{
		if (a[i] >= 97 && a[i] <= 122)
		{
			a[i] -= 32;
		}
		i++;
	}
	return (a);
}

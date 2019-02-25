#include "holberton.h"

/**
 * _strpbrk - searches in string s
 * @s: string
 * @accept: prefix
 *
 * Return: returns a pointer
 */

char  *_strpbrk(char *s, char *accept)
{
	unsigned int i, j;


	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
				return (s+i);
		}
	}
	return (0);
}

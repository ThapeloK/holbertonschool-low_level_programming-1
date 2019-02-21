#include "holberton.h"

/**
 * leet - concatenates two strings
 * @s: string
 *
 * Return: returns pointer
 */

char *leet(char *s)
{
	char c[] = "aAeEoOtTlL";
	char d[] ="43071";
	int i, j, code;

	i = 0;
	code = 0;
	while(s[i])
	{
		for (j = 0; j < 10; j++)
		{
			if (s[i] == c[j])
			{
				code = j / 2;
				s[i] = d[code];
			}
		}
		i++;
	}
	return (s);
}

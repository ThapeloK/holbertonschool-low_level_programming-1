#include "holberton.h"

/**
 * cap_string - converts to uppercase only first letters of a word
 * @a: string
 *
 * Return: returns pointer
 */

char *cap_string(char *a)
{
	int i, inWord;

	i = 0;
	inWord = 1;
	while (a[i])
	{
		if (a[i] == 9 || a[i] == 10 || a[i] == ' ' || a[i] == ',' || a[i] == '}')
		{
			inWord = 1;
		}
		else if (a[i] == ';' || a[i] == '.' || a[i] == '!' || a[i] == '?')
		{
			inWord = 1;
		}
		else if (a[i] == '"' || a[i] == '(' || a[i] == ')' || a[i] == '{')
		{
			inWord = 1;
		}
		else if (inWord == 1 && a[i] >= 97 && a[i] <= 122)
		{
			a[i] -= 32;
			inWord = 0;
		}
		else
			inWord = 0;
		i++;
	}
	return (a);
}

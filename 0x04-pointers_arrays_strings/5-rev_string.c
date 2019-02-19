#include "holberton.h"

/**
* _strlen - returns the length of the string
* @s: takes string
*
* Return: returns the length int
*/

int _strlen(char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

/**
* rev_string - prints stirng in reverse
* @s: takes string
*
* Return: void
*/

void rev_string(char *s)
{
	int len, i;
	char temp;

	len = _strlen(s) - 1;

	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - i];
		s[len - i] = temp;
	}
}

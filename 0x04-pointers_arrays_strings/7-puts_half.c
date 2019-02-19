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
* puts_half - prits half of the string
* @str: takes string
*
* Return: void
*/

void puts_half(char *str)
{
	int len, i;

	len = _strlen(str);
	for (i = (len + 1) / 2; i < len; i++)
	{
		_putchar(*(str + i));
	}
	_putchar('\n');
}

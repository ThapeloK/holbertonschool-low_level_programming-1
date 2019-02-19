#include "holberton.h"

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
* puts2 - prints only odd numbered characters of a string
* @str: takes string
*
* Return: void
*/

void puts2(char *str)
{
	int len, i;

	len = 2 * (_strlen(str) / 2);
	for (i = 0; i < len; i += 2)
	{
		_putchar(*(str + i));
	}
	_putchar('\n');
}

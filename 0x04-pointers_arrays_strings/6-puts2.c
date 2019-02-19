#include "holberton.h"
/**
* puts2 - prints only odd numbered characters of a string
* @str: takes string
*
* Return: void
*/

void puts2(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str += 2;
	}
	_putchar('\n');
}

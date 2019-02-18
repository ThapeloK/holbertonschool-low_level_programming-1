#include "holberton.h"
/**
* _puts - a clone of puts() function
* @str: takes string
*
* Return: void
*/

void _puts(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}

#include "holberton.h"

/**
* print_last_digit - displays the last digit of integer
* @n: takes number
*
* Return: last digit
*/

int print_last_digit(int n)
{
	int a;

	a = n % 10;
	if (a >= 0)
	{
		_putchar(a + '0');
		return (a);
	}
	else
	{
		_putchar((a * -1) + '0');
		return (a * -1);
	}
}

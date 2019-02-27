#include "holberton.h"

/**
 * _pow_recursion - value of x to the power of y
 * @x: takes int
 * @y: takes int
 *
 * Return: x to the power of y
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));
}

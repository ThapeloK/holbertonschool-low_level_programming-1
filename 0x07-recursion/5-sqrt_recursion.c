#include "holberton.h"

/**
 * _sqrt - calculates natural square root of a number
 * @n: takes int
 * @m: takes int
 *
 * Return: returns natural square root of a number
 */

int _sqrt(int n, int m)
{
	if (m * m > n)
		return (-1);
	else if (m * m == n)
		return (m);
	else
		return (_sqrt(n, m + 1));
}

/**
 * _sqrt_recursion - calculates natural square root of a number
 * @n: takes int
 *
 * Return: returns natural square root of a number
 */

int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}

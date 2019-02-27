#include "holberton.h"

/**
 * is_prime - helper function with two parameters
 * @n: takes int
 * @m: takes int
 *
 * Return: 1 or 0
 */

int is_prime(int n, int m)
{
	if (n < 2 || n % 2 == 0)
		return (0);
	if (m > n || m == n)
		return (1);
	if (n % m == 0)
		return (0);
	return (is_prime(n, m + 2));
}


/**
 * is_prime_number - tells if it is prime number
 * @n: takes int
 *
 * Return: 1 or 0
 */

int is_prime_number(int n)
{
	return (is_prime(n, 3));
}

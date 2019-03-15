#include "variadic_functions.h"

/**
 * sum_them_all - sums the n number of arguments
 * @n: the number of arguments
 * Return: returns the result of sum
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list list;
	unsigned int i;
	int sum = 0;

	va_start(list, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(list, int);
	}
	va_end(list);
	return (sum);
}

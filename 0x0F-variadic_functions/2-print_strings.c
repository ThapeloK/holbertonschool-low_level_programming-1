#include "variadic_functions.h"

/**
 * print_strings - prints strings delimited by separator
 * @separator: string delimiter
 * @n: number of arguments
 * Return: Nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list list;
	va_list copy;
	unsigned int i;

	va_start(list, n);
	va_copy(copy, list);
	for (i = 0; i < n; i++)
	{
		printf("%s%s", va_arg(list, char *) ? va_arg(copy, char *) : "(nil)",
		       separator ? (i == n - 1 ? "\n" : separator) : "");
	}
	va_end(list);
}

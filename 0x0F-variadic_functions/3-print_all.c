#include "variadic_functions.h"
/**
 * print_all - mini printf function which uses printf
 * @format: format specifier
 * Return: Nothing.
 */
void print_all(const char * const format, ...)
{
	va_list list;
	int a = 0;
	char *copy, *sep = "";

	va_start(list, format);
	while (format && format[a])
	{
		switch (format[a])
		{
		case 'c':
			printf("%s%c", sep, va_arg(list, int));
			break;
		case 'i':
			printf("%s%i", sep, va_arg(list, int));
			break;
		case 'f':
			printf("%s%f", sep, va_arg(list, double));
			break;
		case 's':
			copy = va_arg(list, char *);
			if (!copy)
				copy = "(nil)";
			printf("%s%s", sep, copy);
			break;
		default:
			a++;
			continue;
		}
		sep = ", ", a++;
	}
	va_end(list);
	putchar('\n');
}

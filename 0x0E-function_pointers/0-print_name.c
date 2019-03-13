#include "function_pointers.h"

/**
 * print_name - prints name, simple pointer to function
 * @name: name
 * @f: function pointer
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		(*f)(name);
}

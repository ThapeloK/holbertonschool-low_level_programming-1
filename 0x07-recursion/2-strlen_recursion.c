#include "holberton.h"

/**
 * _strlen_recursion - prints a length of a string
 * @s: takes string
 *
 * Return: the length
 */

int _strlen_recursion(char *s)
{
	if (*s)
		return (1 + _strlen_recursion(s + 1));
	return (0);
}

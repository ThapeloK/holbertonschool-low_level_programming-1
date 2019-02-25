#include "holberton.h"
#define NULL (void *)0
/**
 * _strchr - locates a character in a string
 * @s: string
 * @c: character
 *
 * Return: returns a pointer
 */

char *_strchr(char *s, char c)
{
	while (*s && *s != c)
	{
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

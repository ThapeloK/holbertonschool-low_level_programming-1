#include "holberton.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: returns true or false
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}


/**
 * _strstr - locates a substring
 * @haystack: string
 * @needle: prefix
 *
 * Return: returns a pointer
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		if (_strcmp(haystack, needle))
			return (haystack);
		haystack++;
	}
	return (0);
}

#include "holberton.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: returns the differences of ASCII characters
 */

int _strcmp(char *s1, char *s2)
{
	int diff, i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	diff = s1[i] - s2[i];
	return (diff);
}

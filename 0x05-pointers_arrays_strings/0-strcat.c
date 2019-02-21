#include "holberton.h"

/**
 * _strlen - returns the length of the string
 * @s: takes string
 *
 * Return: returns the length int
 */

int _strlen(char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: returns pointer
 */

char *_strcat(char *dest, char *src)
{
	int len, i;

	len = _strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[len++] = src[i++];
	}
	dest[len] = '\0';
	return (dest);
}

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
	while (s[count])
	{
		count++;
	}
	return (count);
}


/**
 * str_concat -concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: returns the final string
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int len, len1, len2, i = 0, j = 0;
	char *str;

	if (s1 == NULL)
		len1 = 0;
	else
		len1 = _strlen(s1);
	if (s2 == NULL)
		len2 = 0;
	else
		len2 = _strlen(s2);
	len = len1 + len2;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	for (; i < len1; i++)
		str[i] = s1[i];
	for (; j < len2; j++, i++)
		str[i] = s2[j];
	str[i++] = '\0';
	return (str);
}

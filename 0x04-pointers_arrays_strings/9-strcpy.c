#include "holberton.h"

/**
* _strcpy - copies string
* @dest: takes string
* @src: takes string
*
* Return: void
*/

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i); i++)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';
	return (dest);
}

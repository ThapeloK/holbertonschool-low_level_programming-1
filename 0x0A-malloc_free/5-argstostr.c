#include "holberton.h"

/**
 * argstostr - concatenates all arguments
 * @ac: the size of the array
 * @av: an array of strings
 *
 * Return: A pointer
 */
char *argstostr(int ac, char **av)
{
	int i, j, sum = 0, a;
	char *s;

	if (!ac || !av)
	{
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			sum++;
		}
		sum++;
	}
	s = malloc(sum * sizeof(char) + 1);
	if (s == NULL)
		return (NULL);
	for (i = 0, a = 0; av[i]; i++)
	{
		for (j = 0; av[i][j]; j++, a++)
		{
			s[a] = av[i][j];
		}
		s[a++] = '\n';
	}
	s[a] = '\0';
	return (s);
}

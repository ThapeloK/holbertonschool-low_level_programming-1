#include <stdio.h>
#include <stdlib.h>

/**
 * isError - error checker
 * @argc: number of arguments
 * @argv: an array consisting arguments
 *
 * Return: 0 on  succsess
 */

int isError(int argc, char **argv)
{
	int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
			{
				printf("Error\n");
				exit(98);
			}
		}
	}
	return (0);
}

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
 * _calloc - calloc() implementation
 * @nmemb: number of elements of the array
 * @size: size of a element
 *
 * Return: void
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *s;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	s = malloc(sizeof(char) * nmemb * size);
	if (!s)
		return (NULL);
	for (i = 0; i < nmemb * size; i++)
	{
		s[i] = 0;
	}
	return (s);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: an array consisting arguments
 *
 * Return: 0 or 1
 */

int main(int argc, char **argv)
{
	int len1, len2, carry, a, b, i, j, flag = 0;
	int *result;

	isError(argc, argv);
	len1 = _strlen(argv[1]), len2 = _strlen(argv[2]);
	if (argv[1][0] == 48 || argv[2][0] == 48)
	{
		printf("0\n");
		return(0);
	}
	result = _calloc((len1 + len2), sizeof(char));
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		a = argv[1][i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			b = argv[2][j] - '0';
			carry += result[i + j + 1] + (a * b);
			result[j + i + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[i + j + 1] += carry;
	}
	if (*result == 0)
		result++;
	for (a = 0; a < len1 + len2 - 1; a++)
	{
		printf("%d", result[a]);
	}
	printf("\n");
	return (0);
}

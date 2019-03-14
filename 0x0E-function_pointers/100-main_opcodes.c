#include <stdlib.h>
#include <stdio.h>

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: an array of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int num1;
	char *obj = (char *)main;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	num1  = atoi(argv[1]);
	if (num1 < 0)
	{
		printf("Error\n");
		exit(2);
	}
	while (num1--)
		printf("%02hhx%s", *obj++, num1 == 0 ? "\n" : " ");
	return (0);
	}

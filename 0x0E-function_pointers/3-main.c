#include "3-calc.h"
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
	int num2;
	int (*checker)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	if ((*argv[2] == '/' || *argv[2] == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}
	checker = get_op_func(argv[2]);
	if (!checker)
	{
		printf("Error\n");
		exit(99);
	}
	printf("%d\n", get_op_func(argv[2])(num1, num2));

		 return (0);
		 }

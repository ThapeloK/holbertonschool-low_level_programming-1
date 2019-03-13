#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - entry point
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	int num1 = atoi(argv[1]);
	char *op = argv[2];
	int num2 = atoi(argv[3]);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	if ((*op == '/' || *op == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}
	if (get_op_func(argv[2]) == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	printf("%d\n", get_op_func(argv[2])(num1, num2));

	return (0);
}

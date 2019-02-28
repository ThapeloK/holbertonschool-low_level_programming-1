#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: an array consisting arguments
 *
 * Return: 0 or 1
 */

int main(int argc, char **argv)
{
	int sum = 0, n, i;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	n = atoi(argv[1]);
	if (n <= 0)
		printf("%d\n", 0);
	else
	{
		for (i = 0; i < 5; i++)
		{
			sum += n / coins[i];
			n = n % coins[i];
		}
		printf("%d\n", sum);
	}
	return (0);
}

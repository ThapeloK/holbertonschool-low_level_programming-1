#include <stdio.h>

/**
* main - displays sum of fibonacci numbers
*
* Return: 0
*/

int main(void)
{
	unsigned long int prev, current, next, sum;
	int i;

	prev = 1;
	current = 2;
	for (i = 2; i < 50; i++)
	{
		next = prev + current;
		prev = current;
		current = next;
		if (next <= 4000000 && ((i > 2) && (i % 3) == 0))
		{
			sum += current;
		}
	}
	printf("%lu\n", sum);
	return (0);
}

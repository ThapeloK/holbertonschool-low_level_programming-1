#include <stdio.h>

/**
* main - displays sum of fibonacci numbers
*
* Return: 0
*/

int main(void)
{
	unsigned long int prev, current, next, sum;

	prev = 0;
	current = 2;
	sum = prev + current;
	while (current <= 4000000)
	{
		next = 4 * current + prev;
		if (next > 4000000)
		{
			break;
		}
		prev = current;
		current = next;
		sum += current;
	}
	printf("%lu\n", sum);
	return (0);
}

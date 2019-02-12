#include <stdio.h>

/**
* main - displays the first 98 fibonacci numbers
*
* Return: 0
*/

int main(void)
{
	long double prev, current, next;
	int i;

	prev = 1;
	current = 2;
	printf("%LG, %LG, ", prev, current);
	for (i = 2; i < 99; i++)
	{
		next = prev + current;
		printf("%LG", next);
		prev = current;
		current = next;
		if (i != 98)
			printf(", ");
		else
			putchar('\n');
	}
	return (0);
}

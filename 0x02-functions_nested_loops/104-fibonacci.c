#include <stdio.h>

/**
* main - displays the first 98 fibonacci numbers
*
* Return: 0
*/

int main(void)
{
	double prev, current, next;
	int i;

	prev = 1;
	current = 2;
	printf("%.0f, %.0f, ", prev, current);
	for (i = 2; i < 98; i++)
	{
		next = prev + current;
		printf("%.0f", next);
		prev = current;
		current = next;
		if (i != 97)
			printf(", ");
		else
			putchar('\n');
	}
	return (0);
}

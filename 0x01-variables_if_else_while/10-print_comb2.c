#include <stdio.h>

/**
 *main - Prints combinations of decimal digits using only putchar
 *
 *Description: Prints combinations of decimal digits using only putchar
 *Return: 0
*/
int main(void)
{
	int i, j;

	for (i = 48; i <= 57; i++)
	{
		for (j = 48; j <= 57; j++)
		{
			putchar(i);
			putchar(j);
			if (!(i == 57 && j == 57))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}

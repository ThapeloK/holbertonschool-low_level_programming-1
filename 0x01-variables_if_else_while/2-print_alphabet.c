#include <stdio.h>

/**
 *main - Prints lowercase letters using only putchar
 *
 *Description: Prints lowercase letters using only putchar
 *Return: 0
*/
int main(void)
{
	int i;

	for (i = 97; i <= 122; i++)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);
}

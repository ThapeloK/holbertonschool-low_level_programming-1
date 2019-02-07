#include <stdio.h>

/**
 *main - Prints lowercase and uppercase letters using only putchar
 *
 *Description: Prints lowercase and uppercase letters using only putchar
 *Return: 0
*/
int main(void)
{
	int i;

	for (i = 97; i <= 122; i++)
	{
		putchar(i);
		if (i == 122)
			i -= 58;
		if (i == 90)
			break;
	}
	putchar('\n');
	return (0);
}

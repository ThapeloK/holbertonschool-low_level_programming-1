#include <stdio.h>

/**
* main - displays the first 98 fibonacci numbers
*
* Return: 0
*/

int main(void)
{
	long h1, h2, h3, t1, t2, t3;
	int i, d;

	h1 = 0;
	h2 = 0;
	t1 = 1;
	t2 = 2;
	d = 10000;
	printf("%lu, %lu, ", t1, t2);
	for (i = 2; i <= 97; i++)
	{
		h3 = h1 + h2;
		t3 = t1 + t2;
		if (t3 >= d)
		{
			t3 = t3 % d;
			h3++;
		}
		if (h3 == 0)
			printf("%lu", t3);
		else
			printf("%lu%04lu", h3, t3);
		if (i != 97)
			printf(", ");
		else
			putchar('\n');
		h1 = h2;
		t1 = t2;
		h2 = h3;
		t2 = t3;
	}
	return (0);
}

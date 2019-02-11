#include <stdio.h>

ssize_t write(int fieldes, const void *buff, size_t nbytes);

/**
 * main - simplicity
 * Description: very simple function
 * Return: return 1
 */

int main(void)
{
	write(1,
"and that piece of art is useful\" - Dora Korpar, 2015-10-19\n",
59);
	return (1);
}

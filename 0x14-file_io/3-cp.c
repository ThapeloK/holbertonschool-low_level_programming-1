#include "holberton.h"
#define OUTPUT_BUF_SIZE 1024
#define BUFFER 1024
#define BUF_FLUSH -1

/**
 * main - cp commnad
 * @argc: argumnet count
 * @argv: argument vector
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	ssize_t r, o1, o2, c1, c2;
	char buf[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	if ((o1 = open(argv[1], O_RDONLY)) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if ((o2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while ((r = read(o1, buf, BUFSIZ)) > 0)
	{
		if (write(o2, buf, r) != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if ((c1 = close(o1)) == -1 || (c2 = close(o2)) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %ld\n", c1 == -1 ? c1 : c2);
		exit(100);
	}
	return (0);
}

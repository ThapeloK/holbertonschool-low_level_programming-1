#include "holberton.h"

/**
* _atoi - converts string to an integer
* @s: takes string
*
* Return: returns an integer
*/

int _atoi(char *s)
{
	int i, minus, flag;
	unsigned int n;

	i = 0;
	flag = 0;
	minus = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			n = n * 10 + (s[i] - '0');
			flag++;
		}
		else if (s[i] == '-')
		{
			minus++;
		}
		else if (flag && !(s[i] >= '0' && s[i] <= '9'))
		{
			break;
		}
		i++;
	}
	if (minus % 2 == 0)
		return (n);
	else
		return (-n);
}

#include "holberton.h"

/**
* _abs - displays absolute value of integer
* @n: takes number
*
* Return: absolute value
*/

int _abs(int n)
{
	if (n >= 0)
	{
		return (n);
	}
	else
	{
		return (-1 * n);
	}
}

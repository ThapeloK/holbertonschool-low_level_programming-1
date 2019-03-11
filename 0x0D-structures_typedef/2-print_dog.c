#include "dog.h"
#include <stdio.h>

/**
 * print_dog - prints struct
 * @d: struct
 *
 * Return: void
 */
void print_dog(struct dog *d)
{
	if (d)
	{
		if (d->name == NULL)
			printf("Name: %s\n", "(nil)");
		else
			printf("Name: %s\n", d->name);
		/* if (!(d->age)) */
		/* 	printf("Age: %s\n", "(nil)"); */
		/* else */
			printf("Age: %f\n", d->age);
		if (d->owner == NULL)
			printf("Owner: %s\n", "(nil)");
		else
			printf("Owner: %s\n", d->owner);
	}
}

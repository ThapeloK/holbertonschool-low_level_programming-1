#include "dog.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * new_dog - prints struct
 * @name: name
 * @age: age
 * @owner: owner
 *
 * Return: void
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *our_dog;
	char *c_name, *c_owner;
	int i, j, a, b;

	if (!name || !owner)
		return (NULL);
	our_dog = malloc(sizeof(dog_t));
	if (!our_dog)
		return (NULL);
	for (i = 0; name[i]; i++)
		;
	for (j = 0; owner[j]; j++)
		;
	c_name = malloc(sizeof(char) * i + 1);
	if (!c_name)
	{
		free(our_dog);
		return (NULL);
	}
	for (a = 0; a <= i; a++)
		c_name[a] = name[a];
	c_name[a] = '\0';
	c_owner = malloc(sizeof(char) * j + 1);
	if (!c_owner)
	{
		free(c_name);
		free(our_dog);
		return (NULL);
	}
	for (b = 0; b <= j; b++)
		c_owner[b] = owner[b];
	c_owner[b] = '\0';
	our_dog->name = c_name;
	our_dog->age = age;
	our_dog->owner = c_owner;
	return (our_dog);
}

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
	int i, j;

	our_dog = malloc(sizeof(dog_t));
	if (!our_dog)
		return (NULL);
	for (i = 0; name[i]; i++)
		;
	for (j = 0; owner[j]; j++)
		;
	our_dog->name = malloc(sizeof(char) * i + 1);
	if (!our_dog->name)
	{
		free (our_dog);
		return (NULL);
	}
	our_dog->name = name;
	our_dog->age = age;
	our_dog->owner = malloc(sizeof(char) * j + 1);
	if (!our_dog->owner)
	{
		free (our_dog->name);
		free (our_dog);
		return (NULL);
	}
	our_dog->owner = owner;
	return (our_dog);
}

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

	our_dog = malloc(sizeof(dog_t));
	if (!our_dog)
		return (NULL);
	our_dog->name = malloc(sizeof(name));
	if (!our_dog->name)
		return (NULL);
	our_dog->name = name;
	our_dog->age = age;
	our_dog->owner = malloc(sizeof(owner));
	if (!our_dog->owner)
		return (NULL);
	our_dog->owner = owner;
	return (our_dog);
}

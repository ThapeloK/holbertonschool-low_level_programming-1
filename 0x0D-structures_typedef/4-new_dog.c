#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - duplicates a string
 * @str: string
 *
 * Return: a pointer to the string
 */
char *_strdup(char *str)
{
	char *s;
	int i = 0;

	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		i++;
	}
	s = malloc(sizeof(char) * i + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i++] = '\0';
	return (s);
}

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
	int i, j;

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
	c_name = _strdup(name);
	our_dog->age = age;
	c_owner = malloc(sizeof(char) * j + 1);
	if (!c_owner)
	{
		free(c_name);
		free(our_dog);
		return (NULL);
	}
	c_owner = _strdup(owner);
	our_dog->name = c_name;
	our_dog->owner = c_owner;
	return (our_dog);
}

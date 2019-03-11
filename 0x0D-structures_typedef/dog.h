#ifndef DOG_STRUCT
#define DOG_STRUCT


/**
 * struct dog - Dog struct
 * @name: name of a dog
 * @age: age of the dog
 * @owner: owner
 *
 * Description: dog struct
 */

typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif /* DOG_STRUCT  */

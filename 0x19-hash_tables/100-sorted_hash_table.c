#include "hash_tables.h"

/**
 * shash_table_create - create empty hash table
 * @size: Size of the hash table
 * Return: Hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table = NULL;

	table = calloc(1, sizeof(shash_table_t));
	if (!table)
		return (NULL);
	table->size = size;
	table->array = calloc(size, sizeof(shash_node_t **));
	if (!table->array)
	{
		free(table);
		return (NULL);
	}
	return (table);
}


/**
 * insert_doubly - Populates hash table
 * @ht: hash table
 * @new: new node
 * Return: 1 on success, 0 on failure
 */
void insert_doubly(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *current = NULL, *temp = NULL;

	if (!ht->shead)
		ht->shead = ht->stail = new; /*empty*/
	else
	{
		current = ht->shead;

		while (current->snext)
		{
			if (strcmp(current->key, new->key) > 0)
				break;
			current = current->snext;
		}
		if (strcmp(current->key, new->key) > 0)
		{
			if (current->sprev)
				current->sprev->snext = new;
			new->sprev = current->sprev;
			current->sprev = new;
			new->snext = current;
		}
		else
		{
			new->sprev = current; /*add at the end*/
			new->snext = current->snext;
			current->snext = new;
		}
		temp = new;
		while (temp->snext)
			temp = temp->snext;
		ht->stail = temp;
		temp = new;
		while (temp->sprev)
			temp = temp->sprev;
		ht->shead = temp;
	}
}


/**
 * insert_singly - Populates hash table
 * @ht: hash table
 * @key: Key
 * @value: Value
 * Return: 1 on success, 0 on failure
 */
int insert_singly(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new = NULL;
	unsigned long int hash;

	hash = hash_djb2((unsigned char *)key);
	new = calloc(1, sizeof(shash_node_t));
	if (!new)
		return (0);
	new->key = strdup(key);
	if (!new->key)
	{
		free(new);
		return (0);
	}
	new->value = strdup(value);
	if (!new->value)
	{
		free(new->key), free(new);
		return (0);
	}
	new->next = ht->array[hash % ht->size];
	ht->array[hash % ht->size] = new;

	insert_doubly(ht, new);
	return (1);
}


/**
 * shash_table_set - Populates hash table
 * @ht: hash table
 * @key: Key
 * @value: Value
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int hash;
	shash_node_t *list = NULL;

	if (!key || !ht || !value)
		return (0);
	hash = hash_djb2((unsigned char *)key);
	list = ht->array[hash % ht->size];
	while (list)
	{
		if (!strcmp(list->key, key))
		{
			free(list->value);
			list->value = strdup(value);
			if (!list->value)
				return (0);
			return (1);
		}
		list = list->next;
	}
	return (insert_singly(ht, key, value));
}


/**
 * shash_table_get - gets hash table value based on key
 * @ht: hash table
 * @key: key
 * Return: Value associated with key, NULL if key cannot be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int hash;
	shash_node_t *list = NULL;

	if (!ht)
		return (NULL);
	hash = hash_djb2((unsigned char *)key);
	list = ht->array[hash % ht->size];
	while (list)
	{
		if (!strcmp(list->key, key))
		{
			return (list->value);
		}
		list = list->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints hash table
 * @ht: hash table
 * Return: Nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	size_t c = 0;
	shash_node_t *copy = NULL;

	if (!ht)
		return;
	copy = ht->shead;
	printf("{");
	while (copy)
	{
		if (c != 0)
			printf(", ");
		printf("'%s': ", copy->key);
		printf("'%s'", copy->value);
		copy = copy->snext;
		c++;
	}
	printf("}\n");
}


/**
 * shash_table_print_rev - Prints hash table
 * @ht: hash table
 * Return: Nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	size_t c = 0;
	shash_node_t *copy = NULL;

	if (!ht)
		return;
	copy = ht->stail;
	printf("{");
	while (copy)
	{
		if (c != 0)
			printf(", ");
		printf("'%s': ", copy->key);
		printf("'%s'", copy->value);
		copy = copy->sprev;
		c++;
	}
	printf("}\n");
}


/**
 * shash_table_delete - deletes hash table
 * @ht: hash table
 * Return: Nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	size_t i = 0;
	shash_node_t *array = NULL, *temp = NULL;

	if (!ht)
		return;
	while (i < ht->size)
	{
		if (ht->array[i])
		{
			array = ht->array[i];
			while (array)
			{
				free(array->key);
				free(array->value); /*empty string???*/
				temp = array;
				array = array->next;
				free(temp);
			}
		}
		i++;
	}
	free(ht->array);
	free(ht);
}

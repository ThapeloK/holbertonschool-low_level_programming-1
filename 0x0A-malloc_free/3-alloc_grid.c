#include "holberton.h"

/**
 * alloc_grid - creates 2D array
 * @width: width of the array
 * @height: height of the array
 *
 * Return: pointer to 2D array
 */
int **alloc_grid(int width, int height)
{
	int i, j, a;
	int **arr;

	if (width <= 0 || height <= 0)
		return (NULL);
	arr = malloc(sizeof(int *) * height);
	if (arr == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		arr[i] = malloc(sizeof(int) * width);
		if (arr[i] == NULL)
		{
			for (a = 0; a < i; a++)
				free(arr[a]);
			free(arr);
			return (NULL);
		}
	}
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			arr[i][j] = 0;
		}
	}
	return (arr);
}

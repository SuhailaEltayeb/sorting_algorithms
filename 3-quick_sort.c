#include "sort.h"

void quick_sort(int *array, size_t size);
void swich_integers(int *x, int *y);

/**
 * quick_sort - fucntion to perform quich sorting,
 * using lomuto_sort predefined algorithm.
 * @array: array of integers to be sorted
 * @size: array size
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sorting(array, size, 0, size - 1);
}

/**
 * swich_integers - Function to swap 2 intgers within array
 * @x: 1st integer to be swapped
 * @y: 2nd integer to be swapped.
 *
 * Return: Nothing
 */
void swich_integers(int *x, int *y)
{
	int holder;

	holder = *x;
	*x = *y;
	*y = holder;
}

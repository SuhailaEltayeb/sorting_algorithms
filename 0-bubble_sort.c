#include "sort.h"

/**
 * bubble_sort - function to sort array of ints using bubble sort Alg.
 *
 * @array: list of intigers
 * @size: array size
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t m, n;
	int holder;
	int swapped;

	if (array == NULL || size == 0)
		return;

	for (m = 0; m < size - 1; m++)
	{
		swapped = 0;

		for (n = 0; n < size - m - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				holder = array[n];
				array[n] = array[n + 1];
				array[n + 1] = holder;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}

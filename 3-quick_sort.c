#include "sort.h"

void quick_sort(int *array, size_t size);
void swich_integers(int *x, int *y);
int lomuto_partition(int *array, size_t size, int lowest, int highest);
void lomuto_sorting(int *array, size_t size, int lowest, int highest);

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
/**
 * lomuto_sorting - functio to perform quick sorting on
 * list of integers using Lomunto partitioning.
 * @array: Array of integers to be sorted
 * @size: array size
 * @lowest: lowest indext in the array to be sorted
 * @highest: highest indext in the array to be sorted
 *
 * Return: Nothing
 */
void lomuto_sorting(int *array, size_t size, int lowest, int highest)
{
	int partition;

	if (highest - lowest > 0)
	{
		partition = lomuto_partition(array, size, lowest, highest);
		lomuto_sorting(array, size, lowest, partition - 1);
		lomuto_sorting(array, size, partition + 1, highest);
	}
}
/**
 * lomuto_partition - Order a subset of an array of integers according to
 * the lomuto partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @lowest: lowest index of array to be sorted.
 * @highest: highest index of array to be sorted
 *
 * Return: last partition index.
 */
int lomuto_partition(int *array, size_t size, int lowest, int highest)
{
	int *pivot, lower, upper;

	pivot = array + highest;
	for (upper = lower = lowest; lower < highest; lower++)
	{
		if (array[lower] < *pivot)
		{
			if (upper < lower)
			{
				swich_integers(array + lower, array + upper);
				print_array(array, size);
			}
			upper++;
		}
	}
	if (array[upper] > *pivot)
	{
		swich_integers(array + upper, pivot);
		print_array(array, size);
	}
	return (upper);
}

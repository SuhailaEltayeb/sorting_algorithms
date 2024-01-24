#include "sort.h"

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
 * the lomuto partition scheme (last element as pivot).
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

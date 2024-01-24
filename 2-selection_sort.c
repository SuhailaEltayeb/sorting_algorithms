#include "sort.h"
/**
 * selection_sort - function to sort items in
 * array using selection sort algorithm
 * @array: array to be sorted using selection algorithm
 * @size: size of array to be sorted
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t itr1, itr2, min_idx;
	int holder;

	if (array == NULL || size == 0)
		return;
	for (itr1 = 0; itr1 < size - 1; itr1++)
	{
		min_idx = itr1;
		itr2 = itr1 + 1;

		while (itr2 < size)
		{
			if (array[itr2] < array[min_idx])
			{
				min_idx = itr2;
			}
			itr2++;
		}
		if (min_idx != itr1)
		{
			holder = array[itr1];
			array[itr1] = array[min_idx];
			array[min_idx] = holder;
			print_array(array, size);
		}
	}
}

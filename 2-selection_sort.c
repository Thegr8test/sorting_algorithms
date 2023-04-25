#include "sort.h"

/**
 * swap_ints - Swap two ints
 * @a: first int
 * @b: second int
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort an array of ints
 * @array: array of ints
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int *mini;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		mini = array + i;
		for (j = i + 1; j < size; j++)
			mini = (array[j] < *mini) ? (array + j) : mini;

		if ((array + i) != mini)
		{
			swap_ints(array + i, mini);
			print_array(array, size);
		}
	}
}

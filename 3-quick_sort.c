#include "sort.h"

void swap_ints(int *a, int *b);
int lmto_prtion(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swaps two ints
 * @a: first int
 * @b: second int
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lmto_prtion - Order a subset of an array
 * @array: array of ints
 * @size: size of array
 * @left: starting index
 * @right: ending index
 * Return: partition index
 */
int lmto_prtion(int *array, size_t size, int left, int right)
{
	int *pvt, abve, blw;

	pvt = array + right;
	for (abve = blw = left; blw < right; blw++)
	{
		if (array[blw] < *pvt)
		{
			if (abve < blw)
			{
				swap_ints(array + blw, array + abve);
				print_array(array, size);
			}
			abve++;
		}
	}

	if (array[abve] > *pvt)
	{
		swap_ints(array + abve, pvt);
		print_array(array, size);
	}

	return (abve);
}

/**
 * lomuto_sort - uses the quicksort algorithm via recurssion
 * @array: array of ints
 * @size: size of the array
 * @left: starting index of the array
 * @right: ending index of the array
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lmto_prtion(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of ints
 * @array: array of integers.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

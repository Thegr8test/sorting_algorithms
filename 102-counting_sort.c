#include "sort.h"

/**
 * gt_mximum - Get the mxm val in array
 * @array: array of integers.
 * @size: size of the array.
 * Return: mxm int
 */
int gt_mximum(int *array, int size)
{
	int mxm, i;

	for (mxm = array[0], i = 1; i < size; i++)
	{
		if (array[i] > mxm)
			mxm = array[i];
	}

	return (mxm);
}

/**
 * counting_sort - Sort an array of ints
 * @array: array of ints
 * @size: size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *cnt, *srted, mxm, i;

	if (array == NULL || size < 2)
		return;

	srted = malloc(sizeof(int) * size);
	if (srted == NULL)
		return;
	mxm = gt_mximum(array, size);
	cnt = malloc(sizeof(int) * (mxm + 1));
	if (cnt == NULL)
	{
		free(srted);
		return;
	}

	for (i = 0; i < (mxm + 1); i++)
		cnt[i] = 0;
	for (i = 0; i < (int)size; i++)
		cnt[array[i]] += 1;
	for (i = 0; i < (mxm + 1); i++)
		cnt[i] += cnt[i - 1];
	print_array(cnt, mxm + 1);

	for (i = 0; i < (int)size; i++)
	{
		srted[cnt[array[i]] - 1] = array[i];
		cnt[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = srted[i];

	free(srted);
	free(cnt);
}

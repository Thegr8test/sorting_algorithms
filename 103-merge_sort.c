#include "sort.h"

void merge_sub_arrayays(int *sub_array, int *buff, size_t front, size_t mid,
		size_t back);
void merge_recrsvsort(int *sub_array, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_sub_arrayays - Sort ints
 * @sub_array: sub_arrayay arrays
 * @buff: A buffer
 * @front: front index of an array
 * @mid: middle index of the array
 * @back: back index of the array
 */
void merge_sub_arrayays(int *sub_array, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t l, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_array + front, mid - front);

	printf("[right]: ");
	print_array(sub_array + mid, back - mid);

	for (l = front, j = mid; l < mid && j < back; k++)
		buff[k] = (sub_array[l] < sub_array[j]) ? sub_array[l++] : sub_array[j++];
	for (; l < mid; l++)
		buff[k++] = sub_array[l];
	for (; j < back; j++)
		buff[k++] = sub_array[j];
	for (l = front, k = 0; l < back; l++)
		sub_array[l] = buff[k++];

	printf("[Done]: ");
	print_array(sub_array + front, back - front);
}

/**
 * merge_sort_recursive - use the merge sort algorithm
 * @sub_array: A sub_arrayay
 * @buff: A buffer
 * @front: The front index
 * @back: The back index
 */
void merge_sort_recursive(int *sub_array, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(sub_array, buff, front, mid);
		merge_sort_recursive(sub_array, buff, mid, back);
		merge_sub_arrayays(sub_array, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of ints
 * @array: array of ints
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}

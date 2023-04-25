#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - start
 * Return: 0
 */
int main(void)
{
	int aray[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(aray) / sizeof(aray[0]);

	print_array(aray, n);
	printf("\n");
	bubble_sort(aray, n);
	printf("\n");
	print_array(aray, n);
	return (0);
}

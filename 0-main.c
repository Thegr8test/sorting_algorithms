#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t m = sizeof(array) / sizeof(array[0]);

    print_array(array, m);
    printf("\n");
    bubble_sort(array, m);
    printf("\n");
    print_array(array, m);
    return (0);
}

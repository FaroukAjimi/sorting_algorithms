#include "sort.h"
#include <stdio.h>
/**
  *selection_sort - sorts array using selection sort algorithm
  *@array: array to be sorted
  *@size: size of the array
  */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, k;
	int temp;

	for (i = 0; i < size ; ++i)
	{
		k = i;
		for (j = size - 1; j > i; --j)
		{
			if (array[j] < array[k])
			{
				k = j;
			}
		}
		temp = array[k];
		array[k] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}

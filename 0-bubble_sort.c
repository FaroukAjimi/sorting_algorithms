#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 *bubble_sort - sorts an array using bubble sort algorithm
 *@array: array to be sorted
 *@size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int y = 0;
	int aux = 0;

	y = size;
	while (y > 0)
	{
		for (i = 0; i < y - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				print_array(array, size);
			}
		}
		--y;
	}
}

#include "sort.h"
/**
  *
  *
  *
  */
size_t partition(int *array, size_t start,size_t end, size_t size)
{
	size_t index, i;
	int pivot, temp, temp2;

	pivot = array[end];
	index = start;
	for (i = start; i < end; ++i)
	{
		if (array[i] <= pivot)
		{
			//swap(array[i], array[index]);
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
			index = index + 1;
			print_array(array, size);
		}
	}
	//swap(array[index], array[end]);
	temp2 = array[index];
	array[index] = array[end];
	array[end] = temp2;
	print_array(array, size);
	return index;
}
/**
  *quick_sort_mimicry
  *
  *
  */
void quick_sort_mimicry(int *array, size_t start, size_t end, size_t size)
{
	size_t index;

	if (start < end)
	{
		index = partition(array, start, end, size);
		quick_sort_mimicry(array, start, index - 1, size);
		quick_sort_mimicry(array, index + 1, end, size);
	}
}
/**
  *
  *
  *
  */
void quick_sort(int *array, size_t size)
{
	quick_sort_mimicry(array, 0, size - 1, size);
}

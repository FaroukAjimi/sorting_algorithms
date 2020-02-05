#include "sort.h"
/**
  *partition - partitions the array
  *@array: array to partition
  *@start: start index of the array
  *@end: end index of the array
  *@size: size of the array
  *Return: index
  */
int partition(int *array, int start, int end, size_t size)
{
	int pivot, i, temp, temp2, index;

	pivot = array[end];
	index = start;
	for (i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
			index = index + 1;
			if (index != i)
				print_array(array, size);
		}
	}
	temp2 = array[index];
	array[index] = array[end];
	array[end] = temp2;
	print_array(array, size);
	return (index);
}
/**
  *quick_sort_mimicry - sorts using quick sorts algorithm
  *@array: array to sort
  *@start: start index of the array
  *@end: end index of the array
  *size: size of the array
  */
void quick_sort_mimicry(int *array, int start, int end, size_t size)
{
	int index;

	if (start < end)
	{
		index = partition(array, start, end, size);
		quick_sort_mimicry(array, start, index - 1, size);
		quick_sort_mimicry(array, index + 1, end, size);
	}
}
/**
  *quick_sort - function to sort using quick sort
  *@array: array to sort
  *@size: size of array
  */
void quick_sort(int *array, size_t size)
{
	if (size > 1)
		quick_sort_mimicry(array, 0, size - 1, size);
}

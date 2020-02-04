#include "sort.h"
/**
 *selection_sort - function
 *@array: array
 *@size: size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp;
	(void) size;

	if (array != NULL)
		for (i = 0; array[i] != '\0'; i++)
		{
			k = i;
			for (j = i + 1; array[j] != '\0'; j++)
			{
				if (array[k] > array[j])
					k = j;
			}
			if (k != i)
			{
				temp = array[i];
				array[i] = array[k];
				array[k] = temp;
				print_array(array, size);
			}
		}
}

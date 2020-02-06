#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 *bubble_sort - function
 *@array: hello
 *@size: bye
 *Return: hello
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int y = 0;
	int aux = 0;
	int c = 0;

	while (c == 0)
	{
		y = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				y = y + 1;
				print_array(array, size);
			}
			if (i == size - 2 && y == 0)
			{
				c = c + 1;
			}
		}
	}
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 *insertion_sort_list - gogle
 *@list: List
 *Return : ld
 */
void insertion_sort_list(listint_t **list)
{
	listint_t (*cur);
	listint_t (*tail);
	listint_t(*shift);
	listint_t *tmp;

	if (list != NULL && *list != NULL && (*list)->next != NULL)
	{
		for (cur = (*list)->next; cur != NULL; cur = cur->next)
		{
			tail = cur->prev;
			while (tail != NULL)
			{
				shift = tail->next;
				if (shift->n < tail->n)
				{
					tmp = shift->next;
					if (tmp != NULL)
						tmp->prev = tail;
					tail->next = tmp;
					if (tail->prev != NULL)
						tail->prev->next = shift;
					shift->next = tail;
					shift->prev = tail->prev;
					tail->prev = shift;
					tail = shift;
					if (tail->prev == NULL)
						*list = tail;
					print_list(*list);
				}
				else
					tail = tail->prev;
			}
			if (cur->next == NULL)
				*list = cur;
		}
	}
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}
/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list;
	int array[] = {19, 48, 18, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);
	return (0);
}

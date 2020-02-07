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
	else
		return;
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}

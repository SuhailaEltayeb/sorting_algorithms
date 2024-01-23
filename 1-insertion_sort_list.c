#include "sort.h"

void swich(listint_t *x, listint_t *y);

/**
 * insertion_sort_list - function to sort nodes in DLLL using
 * insertion sort algorithm concept
 * @list: Pointer to DLL head node
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (list == NULL || *list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	for (i = (*list)->next; i; i = i->next)
	{
		for (j = i; j && j->prev && j->prev->n > j->n; j = j->prev)
		{
			swich(j->prev, j);
			if (!j->prev)
				*list = j;
			print_list((const listint_t *)*list);
		}
	}
}
/**
 * swich - function to swap 2 nodes in DLL
 * @x: 1s node address
 * @y: 2nd node address
 *
 * Return: Nohthing
 */
void swich(listint_t *x, listint_t *y)
{
	if (x->prev)
		x->prev->next = y;
	if (y->next)
		y->next->prev = x;
	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;

	if (x->next)
		x->next->prev = x;
	y->next = x;
}

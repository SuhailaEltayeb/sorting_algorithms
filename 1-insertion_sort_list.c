#include "sort.h"

void swich(listint_t *x, listint_t *y);

/**
 * insertion_sort_list - function to sort nodes of a doubly linked list
 * @list: pointer to the head of the doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *itr1, *itr2;

	if (list == NULL || *list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	itr1 = (*list)->next;

	while (itr1)
	{
		itr2 = itr1;
		itr1 = itr1->next;
		while (itr2 && itr2->prev && itr2->prev->n > itr2->n)
		{
			swich(itr2->prev, itr2);
			if (!itr2->prev)
				*list = itr2;
			print_list((const listint_t *)*list);
		}
	}
}
/**
 * swich - function to swap two nodes in a doubly linked list
 * @x: 1st node address
 * @y: 2nd node address
 *
 * Return: void
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
	y->next = x;
}

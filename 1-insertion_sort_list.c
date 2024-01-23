#include "sort.h"

/**
 * swap - function to swap two nodes in a doubly linked list
 * @a: 1st node address
 * @b: 2nd node address
 *
 * Return: void
 */
void swap(listint_t *a, listint_t *b)
{
    if (a->prev)
        a->prev->next = b;

    if (b->next)
        b->next->prev = a;

    a->next = b->next;
    b->prev = a->prev;
    a->prev = b;

    if (a->next)
        a->next->prev = a;

    b->next = a;
}

/**
 * insertion_sort_list - function to sort nodes of a doubly linked list
 * @list: pointer to the head of the doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *i, *j;

    if (!list || !*list || !(*list)->next)
        return;

    for (i = (*list)->next; i; i = i->next)
    {
        for (j = i; j && j->prev && j->prev->n > j->n; j = j->prev)
        {
            swap(j->prev, j);
        }
        
        /* Update the head after inner loop */
        if (!j->prev)
            *list = j;

        print_list((const listint_t *)*list);
    }
}

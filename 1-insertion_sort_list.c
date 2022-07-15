#include "sort.h"
#include <stdio.h>

/**
 * swap_node - Swap two node
 *
 * @head: A pointer to the head of the doubly-linked list.
 * @first: A pointer to the first node to swap.
 * @second: the second node to swap.
 */
void swap_node(listint_t **head, listint_t **first, listint_t *second)
{
	(*first)->next = second->next;

	if (second->next)
		second->next->prev = *first;

	second->prev = (*first)->prev;
	second->next = (*first);

	if ((*first)->prev)
		second->prev->next = second;
	else
		*head = second;

	(*first)->prev = second;
	(*first) = second->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @list: the address of the list that should be sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pivot, *insert, *tmp;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	for (pivot = (*list)->next; pivot; pivot = tmp)
	{
		tmp = pivot->next;
		insert = pivot->prev;
		while (insert && insert->n > pivot->n)
		{
			swap_node(list, &insert, pivot);
			print_list((const listint_t *)*list);
		}
	}
}

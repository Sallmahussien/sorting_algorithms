#include "sort.h"

/**
 * swap_list - exchange two nodes in linked list
 * @list: list to be sorted
 * @curr_node: current node
 * @prev_node: previous node
 */
void swap_nodes(listint_t **list, listint_t  *current_node, listint_t *prev_node)
{
	if (prev_node->prev)
		prev_node->prev->next = current_node;
	else
		*list = current_node;

	if (current_node->next)
		current_node->next->prev = prev_node;

	prev_node->next = current_node->next;
	current_node->prev = prev_node->prev;
	prev_node->prev = current_node;
	current_node->next = prev_node;
}

/**
 * insertion_sort_list - algorithm
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t  *current_node = (*list)->next;
	listint_t *prev_node;

	while (current_node)
	{
		prev_node = current_node->prev;
		while (prev_node)
		{
			if (current_node->n < prev_node->n)
			{
				swap_nodes(&(*list), current_node, prev_node);
				print_list(*list);
			}
			prev_node = prev_node->prev;
		}
		current_node = current_node->next;
	}

}

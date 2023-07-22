#include "sort.h"

/**
 * insertion_sort_list - algorithm
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t  *current_node = (*list)->next;
	listint_t *prev_node;

	if (!(*list) || is_small_list(list))
		return;

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

/**
 * is_small_list - checks if list have less than two element or not
 * @list: list to be sorted
 * Return: true if it has less than two elements, otherwise false
 */
bool is_small_list(listint_t **list)
{
	if (!(*list)->next)
		return (true);

	return (false);
}

/**
 * swap_nodes - exchange two nodes in linked list
 * @list: list to be sorted
 * @curr_node: current node
 * @prev_node: previous node
 */
void swap_nodes(listint_t **list, listint_t  *curr_node, listint_t *prev_node)
{
	if (prev_node->prev)
		prev_node->prev->next = curr_node;
	else
		*list = curr_node;

	if (curr_node->next)
		curr_node->next->prev = prev_node;

	prev_node->next = curr_node->next;
	curr_node->prev = prev_node->prev;
	prev_node->prev = curr_node;
	curr_node->next = prev_node;
}

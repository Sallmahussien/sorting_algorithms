#include "sort.h"

/**
 * insertion_sort_list - algorithm
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node, *prev_node;

	if (!list || !(*list) || is_small_list(list))
		return;

	for (curr_node = (*list)->next; curr_node; curr_node = curr_node->next)
	{
		int data = curr_node->n;

		prev_node = curr_node->prev;

		while (prev_node && prev_node->n > data)
		{
			swap_nodes(list, curr_node, prev_node);
			print_list(*list);
			prev_node = curr_node->prev;
		}
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
void swap_nodes(listint_t **list, listint_t *curr_node, listint_t *prev_node)
{
	prev_node->next = curr_node->next;
	if (curr_node->next)
		curr_node->next->prev = prev_node;

	curr_node->next = prev_node;
	curr_node->prev = prev_node->prev;
	prev_node->prev = curr_node;
	if (curr_node->prev)
		curr_node->prev->next = curr_node;
	else
		*list = curr_node;
}

#include "sort.h"

/**
 * cocktail_sort_list - algorithm
 * @list: linked list to be sorted
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *start;
	listint_t *end;

	if (!list || !(*list) || is_small_list(list))
		return;

	start = *list, end = NULL;

	while (start->next != end)
	{
		end = swap_forward(&(*list), start, end);
		if (!end)
			break;
		start = swap_backward(&(*list), start, end);
		if (!start)
			break;
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
 * swap_forward - swaps forward
 * @list: list to be sorted
 * @start: start node
 * @end: end node
 * Return: end of the next iteration
*/
listint_t *swap_forward(listint_t **list, listint_t *start, listint_t *end)
{
	listint_t *current_node = start;
	listint_t *next_node;
	bool is_swapped = false;

	while (current_node->next != end)
	{
		next_node = current_node->next;
		if (current_node->n > next_node->n)
		{
			swap_nodes(&(*list), next_node, current_node);
			current_node = next_node;
			print_list(*list);
			is_swapped = true;
		}
		current_node = current_node->next;
	}

	return (!is_swapped ? NULL : current_node);
}

/**
 * swap_backward - swaps backward
 * @list: list to be sorted
 * @start: start node
 * @end: end node
 * Return: start of the next iteration
*/
listint_t *swap_backward(listint_t **list, listint_t *start, listint_t *end)
{
	listint_t *current_node = end->prev, *prev_node;
	bool is_swapped = false;

	while (current_node->prev && current_node != start)
	{
		prev_node = current_node->prev;
		if (current_node->n < prev_node->n)
		{
			swap_nodes(&(*list), current_node, prev_node);
			current_node = prev_node;
			print_list(*list);
			is_swapped = true;
		}
		current_node = current_node->prev;
	}

	return (!is_swapped ? NULL : current_node);
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

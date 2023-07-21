#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * enum bool_t - Represents boolean values true and false.
 * @false: Represents the boolean value false, which has the value 0.
 * @true: Represents the boolean value true, which has the value 1.
 */
typedef enum bool_t
{
	false = 0,
	true = 1
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/** printing functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/** Swap two element for sorting arrays*/
void swap(int *first_element, int *second_element);

/** Swap two element for sorting linked lists*/
void swap_nodes(listint_t **list, listint_t *curr_node, listint_t *prev_node);

/** Insertion Sort*/
void insertion_sort_list(listint_t **list);
bool is_small_list(listint_t **list);

/** Bubble Sort*/
void bubble_sort(int *array, size_t size);

/** Selection Sort */
void selection_sort(int *array, size_t size);
int find_minimum_index(const int *array, int start, size_t size);

#endif /* SORT_H */

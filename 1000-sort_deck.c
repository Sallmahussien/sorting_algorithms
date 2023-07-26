#include "deck.h"

/**
 * sort_deck - sorts a deck of cards
 * @deck: deck to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	if (!deck || !(*deck) || !(*deck)->next)
		return;

	sort_deck_kinds(&(*deck));
	sort_deck_values(&(*deck));
}

/**
 * sort_deck_kinds - sorts a deck of cards by kind
 * @decks: deck to be sorted
 */
void sort_deck_kinds(deck_node_t **decks)
{
	deck_node_t *curr_node, *prev_node;

	for (curr_node = (*decks)->next; curr_node; curr_node = curr_node->next)
	{
		kind_t card_kind = curr_node->card->kind;

		prev_node = curr_node->prev;

		while (prev_node && prev_node->card->kind > card_kind)
		{
			swap_cards(decks, curr_node, prev_node);
			prev_node = curr_node->prev;
		}
	}
}

/**
 * sort_deck_values - sorts a deck of cards by value
 * @decks: deck to be sorted
 */
void sort_deck_values(deck_node_t **decks)
{
	deck_node_t *curr_node, *prev_node;

	for (curr_node = (*decks)->next; curr_node; curr_node = curr_node->next)
	{
		prev_node = curr_node->prev;

		while (prev_node &&
					 get_value(prev_node->card->value) > get_value(curr_node->card->value)
					 && curr_node->card->kind == prev_node->card->kind)
		{
			swap_cards(decks, curr_node, prev_node);
			prev_node = curr_node->prev;
		}
	}
}

/**
 * get_value - gets the value of a card
 * @card: card to get value of
 * Return: value of card
 */
int get_value(const char *card)
{
	int i;
	char *cards[] = {"Ace", "2", "3", "4", "5", "6",
						"7", "8", "9", "10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
		if (!strcmp(cards[i], card))
			return (i + 1);

	return (0);
}

/**
 * swap_cards - swaps two cards in a deck
 * @list: deck to swap cards in
 * @curr_node: current node
 * @prev_node: previous node
 */
void swap_cards(deck_node_t **list, deck_node_t *curr_node,
								deck_node_t *prev_node)
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

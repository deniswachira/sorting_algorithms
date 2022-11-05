#include "sort.h"

/**
 * swap_nodes - function that swaps two nodes of a doubly linked list
 * @list: pointer to head of list
 * @node1: pointer to first node
 * @node2: second node
 * Return: nothing
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;

	if (node2->next != NULL)
		node2->next->prev = *node1;

	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*list = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
/**
 * swap_prev - function that swap nodes of a doubly linked list
 * @list: pointer to head of list
 * @node1: pointer to first node
 * @node2: pointer second node
 * Return: nothing
 */
void swap_prev(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *tmp = (*node2)->prev;

	if ((*node2)->next != NULL)
		(*node2)->next->prev = tmp;
	else
		*node1 = tmp;
	tmp->next = (*node2)->next;
	(*node2)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *node2;
	else
		*list = *node2;
	(*node2)->next = tmp;
	tmp->prev = *node2;
	*node2 = tmp;
}

/**
 * cocktail_sort_list - function that sorts a doubly linked
 * list of integers in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to head of list
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int flag = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (flag == 0)
	{
		flag = 1;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, current->next);
				print_list(*list);
				flag = 0;
			}
			current = current->next;
		}
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_prev(list, &current->prev, &current);
				print_list(*list);
				flag = 0;
			}
		}
	}
}

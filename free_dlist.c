#include "monty.h"

/**
 * free_dlist - Function that frees a stack_t list.
 * @head: Pointer with address to head node.
 */

void free_dlist(stack_t *head)
{
	stack_t *copy;

	copy = head;
	while (head)
	{
		copy = head->next;
		free(head);
		head = copy;
	}
}

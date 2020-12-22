#include "monty.h"

/**
 * nop - doesn’t do anything.
 * @stack: Double pointer with address to double linked list stack.
 * @line_number: number of line.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}

/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to stack
 * @line_number: line number of instruction
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *top;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		top = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;

		while (temp->next)
			temp = temp->next;

		temp->next = top;
		top->next = NULL;
		top->prev = temp;
	}
}

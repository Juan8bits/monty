#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to head.
 * @line_n: number of the new node.
 */
void add(stack_t **stack, unsigned int line_n)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->next->n = (*stack)->next->n + (*stack)->n;
		pop(stack, line_n);
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
		free_dlist(*stack);
		free(gv.tokens);
		fclose(gv.fp);
		exit(EXIT_FAILURE);
	}
}

/**
 * sub - substration the top two elements of the stack.
 * @stack: pointer to head.
 * @line_n: number of the new node.
 */
void sub(stack_t **stack, unsigned int line_n)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->next->n = (*stack)->next->n - (*stack)->n;
		pop(stack, line_n);
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_n);
		free_dlist(*stack);
		free(gv.tokens);
		fclose(gv.fp);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_ - Div the top two elements of the stack.
 * @stack: pointer to head.
 * @line_n: number of the new node.
 */
void div_(stack_t **stack, unsigned int line_n)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n != 0)
		{
			temp = (*stack)->next;
			(*stack)->next->n = (*stack)->next->n / (*stack)->n;
			pop(stack, line_n);
			*stack = temp;
		}
		else
		{
			fprintf(stderr, "L%d: division by zero\n", line_n);
			free_dlist(*stack);
			free(gv.tokens);
			fclose(gv.fp);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_n);
		free_dlist(*stack);
		free(gv.tokens);
		fclose(gv.fp);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul - Multiplicate the top two elements of the stack.
 * @stack: pointer to head.
 * @line_n: number of the new node.
 */
void mul(stack_t **stack, unsigned int line_n)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->next->n = (*stack)->next->n * (*stack)->n;
		pop(stack, line_n);
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod -  Function that computes the rest of the division of
 * the second top element of the stack by the top element of the stack.
 * @stack: pointer to head.
 * @line_n: number of the new node.
 */
void mod(stack_t **stack, unsigned int line_n)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n != 0)
		{
			temp = (*stack)->next;
			(*stack)->next->n = (*stack)->next->n % (*stack)->n;
			pop(stack, line_n);
			*stack = temp;
		}
		else
		{
			fprintf(stderr, "L%d: division by zero\n", line_n);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
}

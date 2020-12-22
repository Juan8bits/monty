#include "monty.h"

/**
 * get_function - Function to get pointer to functions
 * @str: Token to compare.
 * @line: line number read.
 * Return: Wild pointer.
 */

void (*get_function(char *str, unsigned int line))(stack_t **, unsigned int)
{
	short int i = 0;
	instruction_t func[] = {
		{"nop", nop},
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", div_},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"rotl", rotl},
		{NULL, NULL}
	};

	while (func[i].opcode)
	{
		if (strcmp(func[i].opcode, str) == 0 || str[0] == '#')
			return (func[i].f);
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, str);
	exit(EXIT_FAILURE);
}

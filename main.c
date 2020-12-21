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
		{NULL, NULL}
	};

	while (func[i].opcode)
	{
		if (strcmp(func[i].opcode, str) == 0 || str[0] == '#')
			return (func[i].f);
		i++;
	}
	fprintf(stderr, "L %d: unknown instruction %s", line, str);
	exit(EXIT_FAILURE);
}

/**
 * parse_buffer - Function that parse the line of the file.
 * @buffer: Pointer with address to the line buffer.
 * Return: Double pointer with address to tokens.
 */
char **parse_buffer(char *buffer)
{
	int n = 1;
	char **line, *token;

	if (!buffer)
		return (NULL);

	line = malloc(sizeof(char *) * 3);
	if (!line)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	line[0] = strtok(buffer, " \t\n");
	while (n < 2 && line != NULL)
	{
		line[n] = strtok(NULL, " \t\n");
		n++;
	}
	line[n] = NULL;
	return (line);
}


/**
 * main - dfsdf
 * @argc: dfsdf
 * @argv: dfsdf
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char buff[1024];
	char *buffer = buff;
	/*int len;*/
	char **tokens = NULL;
	stack_t *stack;
	unsigned int lines = 1;

	stack = NULL;
	if (argc != 1)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen("test", "r");

	if (fp)
	{
		while (fgets(buffer, 1024, (FILE *) fp) != NULL)
		{
			tokens = parse_buffer(buffer);
			if (tokens[1])
				n = atoi(tokens[1]);
			get_function(tokens[0], lines)(&stack, n);
			lines++;
			free(tokens);
			printf("--------------------\n");
		}
		fclose(fp);
		free_dlist(stack);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (0);
}

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

#include "monty.h"

/**
 * parse_buffer - Function that parse the line of the file.
 * @buffer: Pointer with address to the line buffer.
 * Return: Double pointer with address to tokens.
 */
char **parse_buffer(char *buffer)
{
	int n = 1;
	char **line;

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

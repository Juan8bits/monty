#include "monty.h"

/**
 * empty_str - verify is a string is spaces or \n
 * @str: string.
 * Return: 0 on succesful, 1 if failed.
 */

int empty_str(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (str[i] != '\n' && str[i] != ' ')
			return (1);
	return (0);
}

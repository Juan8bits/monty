#include "monty.h"

/**
 * is_number - verify is a string is only numbers.
 * @str: string to verify.
 * Return: 1 if is a number, 0 if not.
 */

int is_number(char *str)
{
	int i = 0;

	if (str)
	{
		if (str[0] == '-')
			i = 1;
		for (; str[i]; i++)
			if (str[i] < 48 || str[i] > 57)
				return (0);
		return (1);
	}
	return (0);
}

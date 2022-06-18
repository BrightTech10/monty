#include "monty.h"

/**
 * isnumber - checks if a string is a number
 *
 * @str: string to be checked
 * Return: returns 0 if string is a number, else 1
 */
int isnumber(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

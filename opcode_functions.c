#include "monty.h"

/**
 * push - pushes an element to a stack
 *
 * @stack: pointer to top of stack
 * @line_number: opcode line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *str_arg; /* element (in string) to be pushed */
	int int_arg; /* element (in int) to be pushed */

	int_arg = 0;
	str_arg = strtok(NULL, "\n "); /* gets element from the line of code */

	/* To convert element (in string) to integer */
	if (isnumber(str_arg) == 0 && str_arg != NULL)
		int_arg = atoi(str_arg);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_to_stack(stack, int_arg);
}

/**
 * pall - prints all values on a stack, from top to bottom
 *
 * @stack: pointer to top of stack
 * @line_number: opcode line number
 */
void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		free(*stack);
		*stack = temp;
	}
}

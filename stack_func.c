#include "monty.h"

/**
 * add_to_stack - to add an element to the top of a stack
 *
 * @head: pointer to top of stack
 * @n: element to be added
 * Return: returns pointer to top of stack
 */
stack_t *add_to_stack(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (!*head)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (*head);
	}

	(*head)->prev = new;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}

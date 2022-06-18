#include "monty.h"

/**
 * main - man fucntion for monty interpreter
 *
 * @argc: number of command line arguments
 * @argv: command line argument (opcode file)
 * Return: returns 0 if successful
 */
int main(int argc, char **argv)
{
	stack_t *stack; /* Pointer to top of stack */

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1], &stack);
	return (0);
}

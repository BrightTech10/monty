#include "monty.h"

/**
 * read_file - reads a bytecode file and runs command
 *
 * @filename: path to file
 * @stack: pointer to top of stack
 */
void read_file(char *filename, stack_t **stack)
{
	char *buffer; /* To store content read from a file */
	char *line;
	instruct_func func;
	int check, line_number;
	size_t file_size;

	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	file_size = sizeof(file);
	buffer = malloc(file_size * sizeof(char));
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	line_number = 1; /* To track line of code */
	while ((getline(&buffer, &file_size, file)) != -1)
	{
		line = parse_line(buffer); /* gets opcode in the line of code */

		func = op_func(line); /* to get opcode function */
		if (func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
			exit(EXIT_FAILURE);
		}
		/* This calls the corresponding opcode function */
		/* 'func' is a placeholder for the corresponding opcode function */
		func(stack, line_number);
		line_number++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(EXIT_FAILURE);
}


/**
 * op_func - checks opcode and returns the correct function
 *
 * @str: opcode
 * Return: returns opcode function, else NULL
 */
instruct_func op_func(char *str)
{
	int i;

	instruction_t command[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL},
	};

	i = 0;
	while (command[i].f != NULL && (strcmp(command[i].opcode, str) != 0))
		i++;
	return (command[i].f);
}

/**
 * parse_line - parses a line for an opcode and its argument
 *
 * @line: line of code to be parsed
 * Return: returns opcode or NULL if it fails
 */
char *parse_line(char *line)
{
	char *op_code;

	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);
	return (op_code);
}

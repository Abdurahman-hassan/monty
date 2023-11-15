#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point for the Monty interpreter program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Description:
 *   The main function serves as the entry point for the Monty interpreter
 *   program. It checks for the correct number of command-line arguments,
 *   opens and processes the specified file, and then frees the memory
 *   allocated for the stack. If the expected number of arguments is not
 *   provided, an error message is printed to stderr, and the program exits
 *   with EXIT_FAILURE.
 *
 * Return: 0 on successful execution.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	open_file(argv[1]);

	free_stack(&head);
	return (0);
}

/**
 * open_file - Opens and reads a file containing stack operations.
 *
 * @filename: The name of the file to be opened and processed.
 *
 * Description:
 *   This function opens the specified file, reads each line, and
 *   processes the stack operations accordingly. It supports the "push"
 *   operation with integer values. If an error occurs during file
 *   opening or processing, an error message is printed to stderr,
 *   and the program exits with EXIT_FAILURE.
 *
 * Return: Nothing.
 */
void open_file(char *filename)
{
	FILE *file_pointer = fopen(filename, "r");
	char *line_buffer = NULL, *opcode = NULL, *value = NULL;
	int line_number = 1;
	size_t line_size = 0;
	int *stack_value = get_stack_val();

	if (file_pointer == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	for (; getline(&line_buffer, &line_size, file_pointer) != -1; line_number++)
	{
		if (*line_buffer == '\n')
			continue;
		line_buffer[strcspn(line_buffer, "\n")] = '\0';
		opcode = strtok(line_buffer, " ");
		value = strtok(NULL, " ");
		if (strcmp(opcode, "push") == 0)
		{
			if (is_number(value) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			*stack_value = atoi(value);
		}
		get_func(opcode, &head, line_number);
	}

	free(line_buffer);
	fclose(file_pointer);
}

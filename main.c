#include "monty.h"

control_block_t ctrl_block = {NULL, NULL, NULL, 0};

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
int main(int argc, char *argv[])
{
    char *line_buffer;
    FILE *monty_file;
    size_t buffer_size = 0;
    ssize_t line_length = 1;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
    }

    monty_file = fopen(argv[1], "r");
    ctrl_block.file_stream = monty_file;
    if (!monty_file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
    }

    while (line_length > 0)
    {
        line_buffer = NULL;
        line_length = getline(&line_buffer, &buffer_size, monty_file);
        ctrl_block.content = line_buffer;
        line_number++;

        if (line_length > 0)
        {
            process_instruction(line_buffer, &stack, line_number, monty_file);
        }

        free(line_buffer);
    }

    free_stack(stack);
    fclose(monty_file);

    return (0);
}


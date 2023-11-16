#include "monty.h"

/**
 * process_instruction - process and executes the given opcode
 * @content: current line from the Monty bytecode file
 * @stack: reference to the top of the stack
 * @line_num: current line number in the bytecode file
 * @bytecode_file: pointer to the opened Monty bytecode file
 * Return: status code, 0 for success
 */
int process_instruction(char *content,
		stack_t **stack, unsigned int line_num, FILE *bytecode_file)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", sum_top_elements},
		{"swap", swap},
		{"nop", do_nothing},
		{"sub", sub_top_elements},
		{"div", div_top_elements},
		{NULL, NULL}
	};
	unsigned int idx = 0;
	char *opcode;

	opcode = strtok(content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0); /* Comment line, skip execution */

	ctrl_block.arg = strtok(NULL, " \n\t");
	while (instructions[idx].opcode && opcode)
	{
		if (strcmp(opcode, instructions[idx].opcode) == 0)
		{
			instructions[idx].f(stack, line_num);
			return (0);
		}
		idx++;
	}
	if (opcode && instructions[idx].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		fclose(bytecode_file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}


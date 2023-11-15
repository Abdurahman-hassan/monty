#include "monty.h"

/**
 * opcode_funcs - Selects the appropriate function to perform
 *                a specific operation based on the opcode.
 *
 * @opcode: The opcode specifying the operation to be performed.
 *
 * Return: A function pointer to the corresponding operation, or
 *         NULL if the opcode is not recognized.
 */
operation *opcode_funcs(char *opcode)
{
	instruction_t operations[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i = 0;

	while (operations[i].opcode)
	{
		if (strcmp(operations[i].opcode, opcode) == 0)
			return (operations[i].f);
		i++;
	}
	return (NULL);
}


/**
 * get_func - Calls the appropriate function based on the given opcode.
 *
 * @opcode: The opcode specifying the operation to be performed.
 * @stack_head: A double pointer to the head of the stack.
 * @line_number: The line number of the opcode in the input file.
 *
 * Description:
 *   This function uses the opcode_funcs function to obtain a function
 *   pointer corresponding to the provided opcode. If a valid function
 *   is found, it is called with the stack_head and line_number as arguments.
 *
 * Return: Nothing.
 */
void get_func(char *opcode, stack_t **stack_head, int line_number)
{
	operation *func = opcode_funcs(opcode);

	if (func != NULL)
		func(stack_head, line_number);
}

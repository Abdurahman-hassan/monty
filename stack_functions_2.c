#include "monty.h"

/**
 * sum_top_elements - sums the top two elements of the stack
 * @stack_top: reference to the top of the stack
 * @line_number: current line number in the script
 * Return: void
 */
void sum_top_elements(stack_t **stack_top, unsigned int line_number)
{
	stack_t *current_node;
	int stack_size = 0, sum;

	current_node = *stack_top;
	/* Count the number of elements in the stack */
	while (current_node)
	{
		current_node = current_node->next;
		stack_size++;
	}

	/* Check if the stack has at least two elements */
	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(ctrl_block.file_stream);
		free(ctrl_block.content);
		free_stack(*stack_top);
		exit(EXIT_FAILURE);
	}

	current_node = *stack_top;
	sum = current_node->n + current_node->next->n;
	current_node->next->n = sum; /* Store sum in the second node */
	/* Move the head of the stack to the second node */
	*stack_top = current_node->next;
	free(current_node); /* Free the original top node */
}

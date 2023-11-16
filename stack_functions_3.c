#include "monty.h"

/**
 * compute_remainder - Computes the remainder of the division of the second
 * top element of the stack by the top element.
 * @stack_top: Pointer to the top of the stack.
 * @line_number: Current line number in the bytecode file.
 * Return: void
 */
void compute_remainder(stack_t **stack_top, unsigned int line_number)
{
	stack_t *current_node;
	int stack_size = 0, remainder;

	current_node = *stack_top;
	/* Count the number of elements in the stack */
	while (current_node)
	{
		current_node = current_node->next;
		stack_size++;
	}

	/* Check if there are at least two elements in the stack */
	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		clean(*stack_top);
	}

	current_node = *stack_top;
	if (current_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		clean(*stack_top);
	}

	remainder = current_node->next->n % current_node->n; /* Compute the remainder */
	/* Store the remainder in the second node from the top */
	current_node->next->n = remainder;
	*stack_top = current_node->next; /* Move the top of the stack down */
	free(current_node); /* Free the original top node */
}


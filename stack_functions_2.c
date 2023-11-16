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
		clean(*stack_top);
	}

	current_node = *stack_top;
	sum = current_node->n + current_node->next->n;
	current_node->next->n = sum; /* Store sum in the second node */
	/* Move the head of the stack to the second node */
	*stack_top = current_node->next;
	free(current_node); /* Free the original top node */
}

/**
 * do_nothing - A function that performs no operation
 * @stack_top: pointer to the top of the stack, not used in this function
 * @line_number: current line number in the bytecode file,
 * not used in this function
 * Return: void
 */
void do_nothing(stack_t **stack_top, unsigned int line_number)
{
	(void)stack_top;   /* Explicitly stating that stack_top is unused */
	(void)line_number; /* Explicitly stating that line_number is unused */
}

/**
 * sub_top_elements - Subtracts the top two elements of the stack.
 * @stack_top: A pointer to the top of the stack.
 * @line_number: The line number where the function is called.
 *
 * This function subtracts the second element from the top of the stack
 * from the top element and stores the result in the second element.
 * The original top element is then removed, and the head of the stack
 * is updated to point to the second element.
 * If the stack does not have at least two elements, an error message is
 * printed to stderr, and the program exits with EXIT_FAILURE.
 *
 * Return: Nothing.
 */
void sub_top_elements(stack_t **stack_top, unsigned int line_number)
{
	stack_t *current_node;
	int stack_size = 0, sub;

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
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		clean(*stack_top);
	}

	current_node = *stack_top;
	sub = current_node->next->n - current_node->n;
	current_node->next->n = sub;
	/* Move the head of the stack to the second node */
	*stack_top = current_node->next;
	free(current_node); /* Free the original top node */
}

/**
 * div_top_elements - Divides the second element from the top of the stack
 * by the top element, and replaces the top element with the result.
 *
 * @stack_top: A pointer to the top of the stack.
 * @line_number: The line number in the source file where the operation occurs.
 *
 * Return: Nothing.
 */
void div_top_elements(stack_t **stack_top, unsigned int line_number)
{
	stack_t *current_node;
	int stack_size = 0, div;

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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		clean(*stack_top);
	}

	current_node = *stack_top;
	if (current_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		clean(*stack_top);
	}
	div = current_node->next->n / current_node->n;
	current_node->next->n = div;
	/* Move the head of the stack to the second node */
	*stack_top = current_node->next;
	free(current_node); /* Free the original top node */
}

/**
 * multiply_top_two - Multiplies the top two elements of the stack.
 * @stack_top: Pointer to the top of the stack.
 * @line_number: Current line number in the bytecode file.
 * Return: void
 */
void multiply_top_two(stack_t **stack_top, unsigned int line_number)
{
	stack_t *current_node;
	int stack_length = 0, product;

	current_node = *stack_top;
	/* Count the elements in the stack */
	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}

	/* Check if there are at least two elements in the stack */
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		clean(*stack_top);
	}

	current_node = *stack_top;
	product = current_node->n * current_node->next->n; /* Calculate the product */
	current_node->next->n = product; /* Store the product in the second node from the top */
	*stack_top = current_node->next; /* Move the top of the stack down */ 
	free(current_node); /* Free the original top node */
}


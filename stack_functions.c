#include "monty.h"

/**
 * push - Adds a new node with a given value to the top of the stack.
 *
 * @stack_head: A double pointer to the head of the stack.
 * @line_number: The line number in the input file.
 *
 * Description:
 *   This function creates a new node with the value obtained from the
 *   stack, and adds it to the top of the stack. If memory allocation fails,
 *   an error message is printed, and the program exits with EXIT_FAILURE.
 *
 * Return: Nothing.
 */
void push(stack_t **stack_head, unsigned int line_number)
{
	int value, idx = 0, invalid = 0;

	if (ctrl_block.arg)
	{
		if (ctrl_block.arg[0] == '-')
			idx++;
		for (; ctrl_block.arg[idx] != '\0'; idx++)
		{
			if (!isdigit(ctrl_block.arg[idx]))
				invalid = 1;
		}
		if (invalid)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(ctrl_block.file_stream);
			free(ctrl_block.content);
			free_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(ctrl_block.file_stream);
		free(ctrl_block.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	value = atoi(ctrl_block.arg);
	if (ctrl_block.mode == 0)
		prepend_node(stack_head, value);
	/* we will add queue */
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 *
 * @stack_head: A double pointer to the head of the stack.
 * @line_number: The line number in the input file.
 *
 * Description:
 *   This function prints all the values on the stack, starting from
 *   the top. If the stack is empty, it does nothing. It traverses the
 *   stack from the top to the bottom and prints each node's value.
 *
 * Return: Nothing.
 */
void pall(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current_node = *stack_head;
	(void) line_number;

	if (current_node == NULL)
		return; /* If the stack is empty, exit the function */

	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 *
 * @stack_head: A double pointer to the head of the stack.
 * @line_number: The line number in the input file.
 *
 * Description:
 *   This function prints the integer value at the top of the stack.
 *   If the stack is empty, it prints an error message to stderr and
 *   exits the program with EXIT_FAILURE. Otherwise, it prints the
 *   value followed by a newline character.
 *
 * Return: Nothing.
 */
void pint(stack_t **stack_head, unsigned int line_number)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack_head)->n);
}

/**
 * pop - Removes the top element from the stack.
 *
 * @stack_head: A double pointer to the head of the stack.
 * @line_number: The line number in the input file.
 *
 * Description:
 *   This function removes the top element from the stack. If the stack is
 *   already empty, it prints an error message to stderr and exits the
 *   program with EXIT_FAILURE. Otherwise, it updates the stack head to
 *   point to the next element, adjusts the previous pointer of the new
 *   head (if applicable), frees the memory of the removed node, and
 *   continues the operation.
 *
 * Return: Nothing.
 */
void pop(stack_t **stack_head, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack_head;
	*stack_head = tmp->next;
	if (*stack_head != NULL)
		(*stack_head)->prev = NULL;
	free(tmp);
}

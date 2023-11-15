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
	int *value = get_stack_val();
	stack_t *new_node = malloc(sizeof(stack_t));
	(void) line_number;

	if (!new_node)
	{
		perror("Error: malloc failed");
		free_stack(stack_head);
		exit(EXIT_FAILURE);
	}
	new_node->n = *value;
	new_node->prev = NULL;
	new_node->next = *stack_head;

	if (*stack_head != NULL)
		(*stack_head)->prev = new_node;

	*stack_head = new_node;
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

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

/**
 * get_stack_val - Retrieves the address of a static variable for stack values.
 *
 * Description:
 *   This function returns the address of a static variable used for storing
 *   values related to stack operations. The static variable retains its
 *   value between function calls, allowing for shared access to a common
 *   stack-related value.
 *
 * Return: A pointer to the static integer variable storing stack values.
 */
int *get_stack_val()
{
	static int value = 1;

	return (&value);
}

/**
 * free_stack - Frees all the nodes in a stack and sets the head to NULL.
 *
 * @stack_head: A double pointer to the head of the stack.
 *
 * Description:
 *   This function frees all the nodes in the stack, starting from the
 *   head, and sets the head pointer to NULL. If the stack or head
 *   pointer is already NULL, it does nothing.
 *
 * Return: Nothing.
 */
void free_stack(stack_t **stack_head)
{
	stack_t *curr;

	if (!*stack_head || !stack_head)
		return;

	while (*stack_head)
	{
		curr = *stack_head;
		*stack_head = (*stack_head)->next;
		free(curr);
	}

	*stack_head = NULL;
}

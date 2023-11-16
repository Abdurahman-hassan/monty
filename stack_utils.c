#include "monty.h"

/**
 * prepend_node - adds a new node
 * at the beginning of the stack
 * @top: pointer to the top of the stack
 * @value: data for the new node
 * Return: void
 */
void prepend_node(stack_t **top, int value)
{
	stack_t *new_node, *temp;

	temp = *top;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = value;
	new_node->next = *top;
	new_node->prev = NULL;
	*top = new_node;
}

/**
 * free_stack - Frees all the nodes in a stack and sets the head to NULL.
 *
 * @top: A double pointer to the head of the stack.
 *
 * Description:
 *   This function frees all the nodes in the stack, starting from the
 *   head, and sets the head pointer to NULL. If the stack or head
 *   pointer is already NULL, it does nothing.
 *
 * Return: Nothing.
 */
void free_stack(stack_t *top)
{
	stack_t *temp;

	temp = top;
	while (top)
	{
		temp = top->next;
		free(top);
		top = temp;
	}
}

/**
 * clean - Frees resources associated with the program and
 * exits with a failure status.
 *
 * @stack_top: A pointer to the top of the stack to be cleaned.
 *
 * Return: Nothing.
 */
void clean(stack_t *stack_top)
{
	fclose(ctrl_block.file_stream);
	free(ctrl_block.content);
	free_stack(stack_top);
	exit(EXIT_FAILURE);
}

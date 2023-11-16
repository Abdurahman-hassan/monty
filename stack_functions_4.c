#include "monty.h"

/**
 * enable_queue_mode - Switches the data structure mode to queue.
 * @stack_head: Pointer to the top of the stack (unused).
 * @line_number: The current line number in the script (unused).
 * Description: This function sets the mode to queue, meaning that elements
 * will be added to the end of the data structure.
 * Return: void
 */
void enable_queue_mode(stack_t **stack_head, unsigned int line_number)
{
	(void)stack_head;
	(void)line_number;
	ctrl_block.mode = 1;
}

/**
 * enable_stack_mode - Switches the data structure mode to stack.
 * @stack_head: Pointer to the top of the stack (unused).
 * @line_number: The current line number in the script (unused).
 * Description: This function sets the mode to stack, meaning that elements
 * will be added to the top of the data structure.
 * Return: void
 */
void enable_stack_mode(stack_t **stack_head, unsigned int line_number)
{
	(void)stack_head;
	(void)line_number;
	ctrl_block.mode = 0;
}

/**
 * append_to_queue - Adds a node to the end of the queue.
 * @queue_head: Pointer to the head of the queue.
 * @value: The value to be added.
 * Description: This function creates a new node with the given value and
 * adds it to the end of the queue.
 * Return: void
 */
void append_to_queue(stack_t **queue_head, int value)
{
	stack_t *new_node, *current;

	current = *queue_head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = NULL;

	/* If queue is empty, set new node as the head */
	if (!current)
	{
		*queue_head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		/* Traverse to the end of the queue */
		while (current->next)
			current = current->next;

		current->next = new_node;
		new_node->prev = current;
	}
}

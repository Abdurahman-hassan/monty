#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void operation(stack_t **, unsigned int);
extern stack_t *head; /* Global Variable */

/* ============= MAIN ============= */

void open_file(char *filename);

/* ============= GET_FUNCTIONS ============= */

operation *opcode_funcs(char *opcode);
void get_func(char *opcode, stack_t **stack_head, int line_number);

/* ============= STACK_FUNCTIONS ============= */

void push(stack_t **stack_head, unsigned int line_number);
void pall(stack_t **stack_head, unsigned int line_number);
int *get_stack_val();
void free_stack(stack_t **stack_head);

/* ============ UTILS ======================== */
int is_number(char *str);
#endif /* MONTY_H */

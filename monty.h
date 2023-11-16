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
 * struct control_block - stores essential variables
 * @arg: command argument
 * @file_stream: pointer to the monty bytecode file
 * @content: content of the current line
 * @mode: indicator for stack or queue mode
 * Description: This structure is used throughout
 * the program to manage state
 */
typedef struct control_block
{
	char *arg;
	FILE *file_stream;
	char *content;
	int mode;
} control_block_t;
extern control_block_t ctrl_block;

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

/* ============= STACK_FUNCTIONS ============= */
void push(stack_t **stack_head, unsigned int line_number);
void pall(stack_t **stack_head, unsigned int line_number);
void pint(stack_t **stack_head, unsigned int line_number);
void pop(stack_t **stack_head, unsigned int line_number);
void swap(stack_t **stack_head, unsigned int line_number);

/* ============= STACK_FUNCTIONS_2 ============= */
void sum_top_elements(stack_t **stack_top, unsigned int line_number);
void do_nothing(stack_t **stack_top, unsigned int line_number);
void sub_top_elements(stack_t **stack_top, unsigned int line_number);
void div_top_elements(stack_t **stack_top, unsigned int line_number);
void multiply_top_two(stack_t **stack_top, unsigned int line_number);

/* ============= STACK_FUNCTIONS_3 ============= */
void compute_remainder(stack_t **stack_top, unsigned int line_number);
void print_char(stack_t **stack_top, unsigned int line_number);
void print_string(stack_t **stack_top, unsigned int line_number);
void rotl(stack_t **stack_top, unsigned int line_number);
void rotr(stack_t **stack_top, unsigned int line_number);

/* ============ UTILS ======================== */
int is_number(char *str);
int isempty(char *str);
int _isalpha(int c);

/* =========== STACK_UTILS =================== */
void prepend_node(stack_t **top, int value);
void free_stack(stack_t *top);
void clean(stack_t *stack_top);

/* =========== PROCESS_INSTRUCTION =========== */
int process_instruction(char *content, stack_t **stack,
		unsigned int line_num, FILE *bytecode_file);

#endif /* MONTY_H */

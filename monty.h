#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define BUFFER_SIZE 2048
#define STACK_FLAG 0
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

/**
 * struct MontyContext - current context
 * @current_arg: argument to the command
 * @operation: opcode command
 * @monty_file_descriptor: descriptor to monty file
 * @line_content: current line content
 * @line_size: current line size
 * @readline: amount of read by getline
 * @line_number: number of current line inside file
 * @stack_or_queue: flag change stack(0) <-> queue(1)
 * Description: carries data through the program
 */
typedef struct MontyContext
{
	char *current_arg;
	char *operation;
	int monty_file_descriptor;
	char *line_content;
	size_t line_size;
	ssize_t readline;
	size_t line_number;
	int stack_or_queue;

} MontyContext;


/**
 * struct MontyController - controller for program flow
 * @current_context: data of program
 * @monty_stack: stack of monty program
 * Description: controls execution of program/data
 */
typedef struct MontyController
{
	MontyContext current_context;
	stack_t *monty_stack;
} MontyController;

extern MontyController monty_controller;
/*utilities.c*/
ssize_t readline(char **lineptr, size_t *n, int stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void init_controller(int monty_file_descriptor);
void exit_program(void);
/*stack_utilities.c*/
stack_t *push_stack(stack_t **head, const int n);
size_t print_stack(const stack_t *h);
void free_stack(stack_t *stack);

/*monty_functions.c*/
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
/*controller.c*/
void execute_controller_flow(void);
void parse(void);
void execute_current_cmd(void);
#endif


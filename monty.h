#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
 * struct MontyContext
 * @current_arg: argument to the command
 * @monty_file: pointer to monty file
 * @content: current line content
 * @line_size: current line size
 * @readline: amount of read by getline
 * @line_number: number of current line inside file
 * @stack_or_queue: flag change stack(0) <-> queue(1)
 * Description: carries data through the program
 */
typedef struct MontyContext
{
    char *current_arg;
    FILE *monty_file;
    char *line_content;
    size_t line_size;
    ssize_t readline;
    size_t line_number;
    int stack_or_queue;

} MontyContext;


/**
 * struct MontyController
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
#endif


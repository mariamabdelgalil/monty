#include "monty.h"

/**
 * monty_queue - make stack format to be FIFo
 *
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_queue(stack_t **stack, unsigned int line_number)
{
	monty_controller.current_context.stack_or_queue = QUEUE_FORMAT;
	(void) stack;
	(void) line_number;
}

/**
 * monty_stack - make stack format to be LIFo
 *
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_stack(stack_t **stack, unsigned int line_number)
{
	monty_controller.current_context.stack_or_queue = STACK_FORMAT;
	(void) stack;
	(void) line_number;
}

#include "monty.h"

/**
 * monty_push - push node to the stack
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_push(stack_t **stack, unsigned int line_number)
{
	int n, arg_idx = 0, not_number = 0;

	if (monty_controller.current_context.current_arg)
	{
		if (monty_controller.current_context.current_arg[0] == '-')
			arg_idx++;
		for (; monty_controller.current_context.current_arg[arg_idx]
				!= '\0'; arg_idx++)
		{
			if (monty_controller.current_context.current_arg[arg_idx] > 57
					|| monty_controller.current_context.current_arg[arg_idx] < 48)
				not_number = 1;
		}
		if (not_number == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit_program();
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit_program();
	}
	n = atoi(monty_controller.current_context.current_arg);
	push_stack(stack, n);
}

/**
 * monty_pall - print the stack
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_pall(stack_t **stack, unsigned int line_number)
{
	print_stack(*stack);
	(void)line_number;
}

/**
 * monty_pint - print the stack top
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit_program();
	}
	printf("%d\n", (*stack)->n);
}

/**
 * monty_pop - pop the stack top
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit_program();
	}
	pop_stack(stack);
}

#include "monty.h"
/**
 * monty_add - add the 2 top stack elements
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int tmp_n;

	if (monty_controller.stack_len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit_program();
	}
	tmp = *stack;
	tmp_n = tmp->n;
	tmp_n += tmp->next->n;
	pop_stack(stack);
	pop_stack(stack);
	push_stack(stack, tmp_n);
	monty_controller.stack_len--;
}

/**
 * monty_nop - perform nothing
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * monty_sub - subtract the 2 top stack elements
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int tmp_n = 0;

	if (monty_controller.stack_len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit_program();
	}
	tmp = *stack;
	tmp_n -= tmp->n;
	tmp_n += tmp->next->n;
	pop_stack(stack);
	pop_stack(stack);
	push_stack(stack, tmp_n);
	monty_controller.stack_len--;
}
/**
 * monty_div - divides the 2 top stack elements
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int tmp_n;

	if (monty_controller.stack_len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit_program();
	}
	tmp = *stack;
	tmp_n = tmp->n;
	if (tmp_n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit_program();
	}
	tmp_n = tmp->next->n / tmp_n;
	pop_stack(stack);
	pop_stack(stack);
	push_stack(stack, tmp_n);
	monty_controller.stack_len--;
}

#include "monty.h"
/**
 * monty_mod - makes mod operation between
 * the 2 top stack elements
 *
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int tmp_n;

	if (monty_controller.stack_len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit_program();
	}
	tmp = *stack;
	tmp_n = tmp->n;
	if (tmp_n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit_program();
	}
	tmp_n = tmp->next->n % tmp_n;
	pop_stack(stack);
	pop_stack(stack);
	push_stack(stack, tmp_n);
	monty_controller.stack_len--;
}
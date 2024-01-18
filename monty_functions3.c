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

/**
 * monty_pchar - prints the char at the top of the stack
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int tmp_n;

	if (monty_controller.stack_len < 1)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit_program();
	}
	tmp = *stack;
	tmp_n = tmp->n;
	if (tmp_n < 0 || tmp_n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit_program();
	}
	printf("%c\n", tmp_n);
}

/**
 * monty_pstr - prints the str at the top of the stack
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}


/**
 * monty_rotl - rotl rotates the stack to the top.
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *new_head;
	stack_t *tail = monty_controller.stack_tail;

	if (monty_controller.stack_len <= 1)
		return;
	new_head = (*stack)->next;
	new_head->prev = NULL;
	tail->next = tmp;
	tmp->next = NULL;
	tmp->prev = tail;
	*stack = new_head;
	monty_controller.stack_tail = tmp;
	(void) line_number;
}

/**
 * monty_rotr - rotr rotates the stack to the bottom.
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: no return
*/
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new_tail;
	stack_t *head = *stack;

	if (monty_controller.stack_len <= 1)
		return;
	tmp = (monty_controller.stack_tail);
	new_tail = tmp->prev;
	new_tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = head;
	*stack = tmp;
	monty_controller.stack_tail = new_tail;
	(void) line_number;
}

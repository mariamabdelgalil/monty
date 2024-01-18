#include "monty.h"

/**
 * execute_controller_flow - execute flow of monty interpreter mainted by
 * monty_controller
 * Return: Void
 */
void execute_controller_flow(void)
{
	while (1)
	{
		monty_controller.current_context.readline =
			readline(&monty_controller.current_context.line_content,
					&monty_controller.current_context.line_size,
					monty_controller.current_context.monty_file_descriptor);
		if (monty_controller.current_context.readline == -1)
			break;
		monty_controller.current_context.line_number++;
		parse();
		if (monty_controller.current_context.operation)
			execute_current_cmd();
		free(monty_controller.current_context.line_content);
		monty_controller.current_context.line_content = NULL;
	}
}

/**
 * parse - parse current monty command
 * Return: Void
 */
void parse(void)
{
	monty_controller.current_context.operation =
				strtok(monty_controller.current_context.line_content, " \n\t");
	monty_controller.current_context.current_arg = strtok(NULL, " \n\t");
}
/**
 * execute_current_cmd - execute current monty command
 * Return: Void
 */
void execute_current_cmd(void)
{

	instruction_t map_op_func[] = {
					{"push", monty_push}, {"pall", monty_pall},
					{"pint", monty_pint}, {"pop", monty_pop},
					{"swap", monty_swap}, {"add", monty_add},
					{"nop", monty_nop}, {"sub", monty_sub},
					{"div", monty_div}, {"mul", monty_mul},
					{"mod", monty_mod},
					{NULL, NULL}
					};
	unsigned int op_idx = 0;

	if (monty_controller.current_context.operation[0] == '#')
		return;
	while (map_op_func[op_idx].opcode)
	{
		if (strcmp(monty_controller.current_context.operation,
					map_op_func[op_idx].opcode) == 0)
		{
			map_op_func[op_idx].f(&monty_controller.monty_stack,
					monty_controller.current_context.line_number);
			return;
		}
		op_idx++;
	}
	if (map_op_func[op_idx].opcode == NULL)
	{
		fprintf(stderr, "L%ld: unknown instruction %s\n",
				monty_controller.current_context.line_number,
				monty_controller.current_context.operation);
		exit_program();
	}
}


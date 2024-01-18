#include "monty.h"

/**
 * push_stack - Adds a new node at the stack of a stack.
 * @head: A pointer to the top of the stack.
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new stack top.
 */
stack_t *push_stack(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_program();
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
	(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}

/**
 * addNodeAfter: add node after given_node
 * @node: A pointer to the node that you will add after.
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node
 */
stack_t *addNodeAfter(stack_t *node, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_program();
	}
	new_node->n = n;
	new_node->prev = node;
	new_node->next = node->next;
	if (node->next)
		node->next->prev = new_node;
	node->next = new_node;

	return (new_node);
}

/**
 * print_stack - Prints all the elements of a stack.
 * @h: The top of the stack.
 *
 * Return: The number of nodes in the stack.
 */
size_t print_stack(const stack_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (nodes);
}

/**
* free_stack - frees a stack
* @stack: top of the stack
*/
void free_stack(stack_t *stack)
{
	stack_t *temp;

	temp = stack;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
/**
* pop_stack - frees a stack
* @stack: pointer to top of the stack
*/
void pop_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	*stack = temp->next;
	if (temp->next)
		temp->next->prev = NULL;
	free(temp);
}

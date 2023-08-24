#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 *
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number of the opcode in the file.
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");

	if (!arg || is_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer.\n", line_number);
		exit(EXIT_FAILURE);
	}

	int value = atoi(arg);
	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * pall - Printd values onto the stack,
 *
 * @stack: Pointer to the beginning of the stack.
 * @line_number: Line number of the opcode in file.
 */

void (stack **stack, unsigned int line_number)
{
	/*unused parameter*/
	(void)line_number;

	stack_t *current = *stack;
	while (current)
	{
		printf("%d.\n", current->n);
		current = current->next;
:	}
}

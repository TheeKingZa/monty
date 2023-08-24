#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Check if a string is and integer.
 *
 * @str: Pointer to the string.
 *
 * Return: 1 if the string is an int, 0 otherwise.
 */

/* Declare is_integer function */
int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (0);
/* Empty string or NULL pointer is not an integer */
	}
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	while (*str != '\0')
	{
	if (*str < '0' || *str > '9')
	{
	return (0);
	}
        str++;
	}
	return (1);
}

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
		free_stack(*stack);
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

void pall(stack_t **stack, unsigned int line_number)
{
	/*unused parameter*/
	(void)line_number;

	stack_t *current = *stack;
	while (current)
	{
		printf("%d.\n", current->n);
		current = current->next;
	}
}

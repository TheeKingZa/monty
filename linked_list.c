#include "linked_list.h"
/* Define your linked list functions */
/**
 * push - Add a new node at the beginning of the stack.
 *
 * @stack: Pointer to the pointer to the stack.
 * @value: Value to be added to the stack.
 *
 * This function adds a new node with the given value to the stack.
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 * pall - Print all elements of the stack.
 *
 * @stack: Pointer to the stack.
 *
 * This function prints all the elements in the stack.
 */

void pall(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}

/* Implement more linked list functions here as needed */

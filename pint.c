#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pint - Prints the value at the TOP of the stack.
 *
 * @stack: Double pointer to beginning of stack.
 * @line_number: libe number of the opcode in file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty.\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

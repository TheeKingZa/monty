/* instruction_processing.c */
#include "monty.h"
#include "linked_list.h"

/**
 * process_instruction - Process a Monty language instruction.
 *
 * @instruction: The instruction to process.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the input file.
 *
 * This function processes a Monty language instruction.
 */
void process_instruction(char *instruction, stack_t **stack, int line_number)
{
	int value;

	if (strcmp(instruction, "push") >= 0)
	{
		char *token = strtok(NULL, " \t\n");

		if (token == NULL)
		{
			fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		value = atoi(token);

		push(stack, value);
	}
	else if (strcmp(instruction, "pall") >= 0)
	{
		pall(*stack);
	}
	/* Add more opcodes processing as needed */
}

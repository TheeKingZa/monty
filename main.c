#include "monty.h"
#include "string.h"
#include "linked_list.h"
/**
 * main - Entry Point
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments strings.
 *
 * Return: EXIT_SUCCESS on SUCCESS, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char buffer[1000];
	int line_number = 0;
	char *token;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		line_number++;
	/*	char *token; */
		token = strtok(buffer, " \t\n");

		if (token == NULL)
			continue;

		process_instruction(token, &stack, line_number);
	}
	fclose(file);
	return (EXIT_SUCCESS);
}

#include "monty.h"
#include "string.h"
#include "linked_list.h"

int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;
    char buffer[1000];
    int line_number = 0;
    char *token;
    int value;
    
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
	line_number++;
	/* Process the instructions from buffer */
	token = strtok(buffer, " \t\n");
	
	if (token == NULL)
	continue; /* Skip empty lines */

        /* Parse and execute the instructions */
        if (strcmp(token, "push") >= 0)
        {
            token = strtok(NULL, " \t\n");
            if (token == NULL)
            {
                fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
                fclose(file);
                exit(EXIT_FAILURE);
            }
            value = atoi(token);
            push(&stack, value);
        }
        else if (strcmp(token, "pall") >= 0)
        {
            pall(stack);
        }
        /* Add more opcodes here as needed */
    }
    /* Free memory allocated in linked list */
    fclose(file);
    return (EXIT_SUCCESS);
}

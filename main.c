#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <string.h>

int main(int argc, char *argv[])
{
        FILE *file;
        char *line_content = NULL;
        size_t length = 0;
        unsigned int line_number = 0;
        stack_t *stack = NULL;
        char *opcode, *arg;
	int number;

        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }

        file = fopen(argv[1], "r");
        if (file == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }

        while (getline(&line_content, &length, file) != -1)
        {
                line_number++;
		opcode = strtok(line_content, " \t\n");

                if (opcode == NULL || opcode[0] == '#')
                        continue;
/*		execute_op(opcode, strtok(NULL, " \t\n"), &stack, line_number);
		*/

                if (strcmp(opcode, "push") == 0)
                {
			arg = strtok(NULL, " \t\n");
                        if (arg == NULL || !valid_number(arg))
                        {
                                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                                free(line_content);
                                fclose(file);
				free_stack(stack);
                                exit(EXIT_FAILURE);
                        }
                        number = atoi(arg);
                        push_op(&stack, line_number, number);
                }
                else if (strcmp(opcode, "pall") == 0)
                {
                        pall_op(&stack, line_number);
                }
                else if(strcmp(opcode, "pint") == 0)
                {
			 pint_op(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instructions %s\n", line_number, opcode);
                        free(line_content);
                        fclose(file);
                        exit(EXIT_FAILURE);
                }
        }

        free(line_content);
        fclose(file);
        free_stack(stack);
        return 0;
}

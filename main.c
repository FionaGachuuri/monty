#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <string.h>

int main(int argc, char *argv[])
{
        FILE *file;
        char *line = NULL;
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

        while (getline(&line, &length, file) != -1)
        {
                line_number++;
		
		opcode = strtok(line, " \t\n");

                if (opcode == NULL || opcode[0] == '#')
                        continue;

                if (strcmp(opcode, "push") == 0)
                {
			arg = strtok_r(NULL, " \t\n",&line);
                        if (arg == NULL || !valid_number(arg))
                        {
                                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                                free(line);
                                fclose(file);
                                exit(EXIT_FAILURE);
                        }
                        number = atoi(arg);
                        push(&stack, line_number, number);
                }
                else if (strcmp(opcode, "pall") == 0)
                {
                        pall(&stack, line_number);
                }
                else
                {
                        fprintf(stderr, "L%u: unknown instructions %s\n", line_number, opcode);
                        free(line);
                        fclose(file);
                        exit(EXIT_FAILURE);
                }
        }

        free(line);
        fclose(file);
        free_stack(stack);
        return 0;
}

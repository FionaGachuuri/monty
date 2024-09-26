#include "monty.h"

/**
  *execute_op -function that executes a given opcode
  *@opcode: the operationcpode to execute
  *@arg: argument for the operation code(integer)
  *@stack: double pointer to the top (head) of the stack
  *@line_number: current line number in the bytecode file
  */

void execute_op(char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
        int n;

        if (strcmp(opcode, "push") == 0)
        {
                if (arg == NULL || !valid_number(arg))
                {
                        fprintf(stderr, "L%d: usage: push integer\n", line_number);
                        exit(EXIT_FAILURE);
                }

                n = atoi(arg);
                push_op(stack, line_number, n);
        }
        else if (strcmp(opcode, "pint") == 0)
        {
                pint_op(stack, line_number);
        }
        else
        {
                fprintf(stderr, "L%d: unknown instructions %s\n", line_number, opcode);
                exit(EXIT_FAILURE);
        }
}


/**
  *valid_number -function that checks if a string rep a valid integer.
  *@arg: string to be checked.
  *Return: 1 if its a valid integer, or 0 if otherwise.
  */

int valid_number(const char *arg)
{
        if (arg == NULL || *arg == '\0')
        {
                return (0);
        }
        if (*arg == '-' || *arg == '+')
        {
                arg++;
        }
        while (*arg)
        {
                if (*arg < '0' || *arg > '9')
                {
                        return (0);
                }
                        arg++;
        }
        return (1);
}

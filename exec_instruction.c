#include "monty.h"

/**
 * exec_instruction - Executes opcodes
 * @command: opcode to be executed
 * @stack: Doubly linked list stack structure
 * @line_number: Line number of op_code
 *
 * Return: Nothing
 */
void exec_instruction(char *command, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t command_struct[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"#", op_comment},
		{NULL, NULL}
	};

	while (command_struct[i].opcode != NULL)
	{
		if (strcmp(command_struct[i].opcode, command) == 0)
		{
			command_struct[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, command);
	exit(EXIT_FAILURE);
}

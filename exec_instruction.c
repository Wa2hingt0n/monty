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
		{NULL, NULL}
	};

	while (command_struct[i].opcode != NULL)
	{
		if (strcmp(command_struct[i].opcode, command) == 0)
		{
			/*printf("Before opcode execution\n");*/
			command_struct[i].f(stack, line_number);
			/*printf("After opcode execution\n");*/
			return;
		}
		i++;
	}

	/*write(STDERR_FILENO, "L", 1);
	write(STDERR_FILENO, line_number, 2);
	write(STDERR_FILENO, ": unknown instruction ", 22);
	write(STDERR_FILENO, command, strlen(*command));
	write(STDERR_FILENO, "\n", 2);*/
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, command);
	exit(EXIT_FAILURE);

}

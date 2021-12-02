#include "monty.h"

/**
 * argc_error - Prints argument count error
 *
 * Return: EXIT_FAILURE
 */
void argc_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * file_open_error - Prints error on failure to open a file
 * @filename: Name of file failed to open
 *
 * Return: EXIT_FAILURE
 */
int file_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * invalid_op_error - Prints error message in case of invalid opcode
 * @opcode: Opcode
 * @line_number: Line number in Monty bytecodes file
 *
 * Return: EXIT_FAILURE
 */
int invalid_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

#include "monty.h"

/**
 * op_mod - Computes the modulus of the second element by the first element
 * @stack: Pointer to the beginning of the stack
 * @line_number: Line number of opcode in Monty ByteCode file
 *
 * Return: Nothing
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *node_result;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	node_result = tmp->next;
	result = node_result->n % tmp->n;
	node_result->n = result;
	op_pop(stack, line_number);
}

/**
 * op_comment - Recognizes comments and does nothing to the line
 * @stack: Pointer to the beginning of the stack
 * @line_number: Line number of opcode in Monty ByteCode file
 *
 * Return: Nothing
 */
void op_comment(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
}

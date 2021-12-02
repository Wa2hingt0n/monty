#include "monty.h"

/**
 * op_add - Adds the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in the Monty ByteCode file
 *
 * return: Nothing
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *tmp, *node_result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	node_result = tmp->next;
	result = tmp->n + (node_result)->n;
	node_result->n = result;
	op_pop(stack, line_number);
}

/**
 * op_nop - Does nothing
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in the Monty ByteCode file
 *
 * return: Nothing
 */
void op_nop(__attribute__((unused)) stack_t **stack, __attribute__((unused))
	    unsigned int line_number)
{
}

/**
 * op_sub - Subtracts the top element from the second element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in the Monty ByteCode file
 *
 * return: Nothing
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *tmp, *node_result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	node_result = tmp->next;
	result = (node_result)->n - tmp->n;
	node_result->n = result;
	op_pop(stack, line_number);
}

/**
 * op_div - Divides the top element by the second element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in the Monty ByteCode file
 *
 * return: Nothing
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *tmp, *node_result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
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
	result = (node_result)->n / tmp->n;
	node_result->n = result;
	op_pop(stack, line_number);
}
/**
 * op_mul - Multiplies the top element by the second element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in the Monty ByteCode file
 *
 * return: Nothing
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *tmp, *node_result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	node_result = tmp->next;
	result = (node_result)->n * tmp->n;
	node_result->n = result;
	op_pop(stack, line_number);
}

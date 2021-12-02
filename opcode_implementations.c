#include "monty.h"

/**
 * op_push - Adds an element to the top of a stack
 * @stack: Pointer to the top of the stack
 * @line_number: Position of opcode in ByteCode file
 *
 * Return: Nothing
 */
void op_push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = push_arg;
	node->prev = NULL;

	if (*stack == NULL)
	{
		node->next = NULL;
		*stack = node;
		return;
	}
	node->next = *stack;

	(*stack)->prev = node;
	*stack = node;
}

/**
 * op_pall - Prints all the values on the stack starting from the top
 * @stack: Pointer to the top of the stack
 * @line_number: Position of opcode in ByteCode file
 *
 * Return: Nothing
 */
void op_pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL)
		return;
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * op_pint - Prints the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in Monty ByteCode file
 *
 * Return: Nothing
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * op_pop - Removes the top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in Monty ByteCode file
 *
 * Return: Nothing
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * op_swap - Swaps the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in Monty ByteCode file
 *
 * Return: Nothing
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1;
	stack_t *tmp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp1 = *stack;
	tmp2 = (*stack)->next;
	tmp1->prev = tmp2;
	tmp2->prev = NULL;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;

	*stack = tmp2;
}

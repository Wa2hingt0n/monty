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
	/*printf("Before malloc in push function\n");*/
	if (node == NULL)
	{
		/*write(STDERR_FILENO, "Error: malloc failed\n", 22);*/
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = push_arg;
	node->prev = NULL;

	/*printf("After malloc, before if stack is NULL statement\n");*/

	if (*stack == NULL)
	{
		node->next = NULL;
		*stack = node;
		/*printf("Before return in if stack is NULL statement\n");*/
		return;
	}
	/*printf("After if stack is NULL statement\n");*/
	node->next = *stack;
	/*printf("After node->next = *stack statement\n");
	  printf("After node->next = *stack statement\n");*/
	/*printf("After node->next = *stack statement\n");*/
	(*stack)->prev = node;
	/*printf("After stack->prev = node statement\n");*/
	*stack = node;
	/*printf("At end of push function\n");*/
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
		/*printf("Before pall\n");*/
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	/*printf("After pall loop\n");*/
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

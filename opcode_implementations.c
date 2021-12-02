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

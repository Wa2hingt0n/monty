<<<<<<< HEAD
#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
=======
#ifndef _MONTY_H_
#define _MONTY_H_

>>>>>>> 40f27ee7e314f0ed77bb4694f0f52584d97861ea
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
<<<<<<< HEAD
#include <fcntl.h>

/* Integer argument to the push opcode variable declaration*/
int push_arg;
=======
#include <ctype.h>
>>>>>>> 40f27ee7e314f0ed77bb4694f0f52584d97861ea

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
<<<<<<< HEAD
 * Description: doubly linked list structure
=======
 * Description: doubly linked list node structure
>>>>>>> 40f27ee7e314f0ed77bb4694f0f52584d97861ea
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
<<<<<<< HEAD
	int n;
	struct stack_s *prev;
	struct stack_s *next;
=======
        int n;
        struct stack_s *prev;
        struct stack_s *next;
>>>>>>> 40f27ee7e314f0ed77bb4694f0f52584d97861ea
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
<<<<<<< HEAD
 * for stack, queue, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* string_tokenizing*/
char *_strtok(char *str, unsigned int line_number);

/*opcode_implementations*/
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);

/* exec_instruction*/
void exec_instruction(char *command, stack_t **stack, unsigned int line_number);

#endif /* !MONTY_H */
=======
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif
>>>>>>> 40f27ee7e314f0ed77bb4694f0f52584d97861ea

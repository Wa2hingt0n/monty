#include "monty.h"
#include <stdio.h>

/**
 * main - Monty ByteCode Interpreter
 * @argc: Number of arguments to the program
 * @argv: Array of arguments to main function
 *
 * Return: Always 0(success)
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	ssize_t chars_read;
	char *r_buffer = NULL;
	char *commands;
	size_t bytes_read = 0;
	unsigned int line_number = 1;
	stack_t *stack = NULL, *tmp_free;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fd = fopen(argv[1], "r");
		if (fd == NULL)
		{
			fprintf(stderr, "Error: can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}

		while ((chars_read = getline(&r_buffer, &bytes_read, fd)) != -1)
		{
			commands = _strtok(r_buffer, line_number);
			if (commands != NULL)
				exec_instruction(commands, &stack, line_number);
			line_number++;
		}
		free(r_buffer);
		while (stack)
		{
			tmp_free = stack->next;
			free(stack);
			stack = tmp_free;
		}
		fclose(fd);
	}
	return (0);
}

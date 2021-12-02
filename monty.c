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
	stack_t *stack = NULL;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 19);
		exit(EXIT_FAILURE);
	}
	else
	{
		fd = fopen(argv[1], "r");
		if (fd == NULL)
		{
			/*write(STDERR_FILENO, "Error: Can't open file ", 23);
			write(STDERR_FILENO, argv[1], strlen(argv[1]));
			write(STDERR_FILENO, "\n", 1);*/
			fprintf(stderr, "Error: can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}


		while ((chars_read = getline(&r_buffer, &bytes_read, fd))!= -1)
		{
			/*printf("Before strtok\n");*/
			commands = _strtok(r_buffer, line_number);
			/*printf("After strtok\n");*/
			if (commands != NULL)
				exec_instruction(commands, &stack, line_number);
			line_number++;
		}
		free(r_buffer);
		fclose(fd);
	}
	return (0);
}

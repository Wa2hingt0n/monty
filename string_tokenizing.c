#include "monty.h"

/**
 * _strtok - Tokenizes a string
 * @str: String to be tokenized
 * @line_number: line number of opcode.
 * Return: Pointer to an array of tokenized strings
 */
char *_strtok(char *str, unsigned int line_number)
{
	char *tokens;
	char *argv;
	int i = 0; /*argv_size = 32;*/

	tokens = strtok(str, " \t\n");
	if (tokens == NULL)
		return (NULL);



	argv = tokens;
	tokens = strtok(NULL, " \n\t");
	if (tokens != NULL)
	{
		i++;
		push_arg = atoi(tokens);
	}
	else if (tokens == NULL && strcmp(argv, "push") == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}


	return (argv);
}

#include "monty.h"

/**
 * _strtok - Tokenizes a string
 * @str: String to be tokenized
 *
 * Return: Pointer to an array of tokenized strings
 */
char *_strtok(char *str, unsigned int line_number)
{
	char *tokens;
	char *argv;
	int i = 0; /*argv_size = 32;*/

	tokens = strtok(str, " \t\n");
	if (tokens == NULL)
		return NULL;

	/*argv = malloc(sizeof(char *) * argv_size);
	if (argv == NULL)
	{
		write(STDERR_FILENO, "Error: malloc failed\n", 22);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}*/

	argv = tokens;
	tokens = strtok(NULL, " \n\t");
	if (tokens != NULL)
	{
		i++;
		push_arg = atoi(tokens);
	}
	else if (tokens == NULL && strcmp(argv, "push") == 0)
	{
		/*write(STDERR_FILENO, "Usage: push integer\n", 21);*/
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*while (tokens != NULL && i < 2)
	{
		argv[i] = tokens;
		if (i == 1)
		{
			argv[i] = atoi(argv[i]);
		}
		tokens = strtok(NULL, " \t\n");
		i++;
		}*/
	/*argv[i] = NULL;*/

	return (argv);
}

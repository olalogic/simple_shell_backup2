#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * start_shell - starts our loop looking for user's commands
 *
 * Return: 0 on success, anything else on failure, error code dependent
 */
int start_shell(void)
{
	char *input = NULL;
	size_t input_buff_size = 0;
	ssize_t bytes_read = 0;
	queue_t *com_q = NULL;

	/* register our signal handlers with kernal for things like SIGINT */
	if (register_signal_handlers() < 0)
		return (-1);
	/* loop through and get user input */
	while (1)
	{
		print_prompt();
		printf("trying to alloc input line\n");
		bytes_read = getline(&input, &input_buff_size, stdin);
		printf("succeded in alloc\n");
		if (bytes_read < 0 || input[0] == '\n')
		{
			if (bytes_read < 0)
				write(STDOUT_FILENO, "\n", 1);
			if (input)
			{
				free(input); /* input still got malloced */
				input = NULL;
			}
			continue; /* ask for input again */
		}
		com_q = parse_string(input);
		if (!com_q)
			return (-1); /* failed to create list of commands */

		if (input)
		{
			free(input);
			input = NULL;
		}

		if (execute_commands(com_q) < 0)
			return (-1); /* failed to execute commands */
		free_command_queue(com_q);
	}

	return (0);
}
/**
 * print_prompt - prints the prompt for user to input command
 *
 * Return: always void.
 */
void print_prompt(void)
{
	write(STDOUT_FILENO, "> ", 2);
}

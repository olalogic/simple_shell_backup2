#include "shell.h"
#include <stdio.h>
#include <unistd.h>
/**
 * start_shell - starts our loop looking for user's commands
 *
 * Return: 0 on success, anything else on failure, error code dependent
 */
int start_shell()
{
	char *input = NULL;
	size_t input_buff_size = 0;
	int err = 0;
	queue_t *com_q = NULL;

	while (1)
	{
		print_prompt();
		if (getline(&input, &input_buff_size, stdin) < 0)
			return (-1); /* overflow error or NULL linep/linecapp */
		com_q = parse_string(input);
		if (!com_q)
			return (-1); /* failed to create list of commands */
		if (execute_commands(com_q) < 0)
			return (-1); /* failed to execute commands */
		free_command_queue(com_q);
	}
}
/**
 * print_prompt - prints the prompt for user to input command
 *
 * Return: always void.
 */
void print_prompt()
{
	write(STDOUT_FILENO, "> ", 2);
}

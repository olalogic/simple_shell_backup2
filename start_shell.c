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
	command_t *head = NULL;

	while (1)
	{
		print_prompt();
		if (getline(&input, &input_buff_size, stdin) < 0)
			return (-1); /* overflow error or NULL linep/linecapp */
		head = parse_string(input);
		if (!head) 
			return (-1); /* failed to create list of commands */
		if (execute_commands(head) < 0)
			return (-1); /* failed to execute commands */
		free_command_list(head);
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

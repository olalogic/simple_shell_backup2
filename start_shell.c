#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * start_shell - starts our loop looking for user's commands
 *
 * @environ: array of environmental variables
 * @exec_name: name of executable (name of our shell)
 *
 * Return: 0 on success, anything else on failure, error code dependent
 */
int start_shell(char **environ, char *exec_name)
{
	char *input = NULL;
	size_t input_buff_size = 0;
	ssize_t bytes_read = 0;
	queue_t *com_q = NULL;
	his_q_t *his_q = NULL;

	if (register_signal_handlers() < 0)
		return (-1);
	his_q = get_history();
	if (!his_q)
		return (-1); /* failed to create history queue */
	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_prompt();
		bytes_read = getline(&input, &input_buff_size, stdin);
		if (bytes_read < 0 || input[0] == '\n')
		{
			if (input)
			{
				free(input);
				input = NULL;
			}
			if (bytes_read < 0)
			{
				if (isatty(STDIN_FILENO))
					print_newline();
				fflush(stdin);
				return (0); /* EOF received, exit shell */
			}
			continue;
		}
		fflush(stdin);
		com_q = parse_string(input);
		if (!com_q)
			return (-1); /* failed to create list of commands */
		if (input)
		{
			h_enqueue(his_q, input); /* add command to history */
			free(input);
			input = NULL;
		}
		if (execute_commands(his_q, com_q,
					environ, exec_name) < 0)
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

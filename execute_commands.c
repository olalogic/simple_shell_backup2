#include "shell.h"
/**
 * execute_commands - executes a queue of commands in FIFO order
 * @command_q: the queue of commands to execute
 *
 * Return: 1 (success) 0 (failure).
 */
int execute_commands(queue_t *command_q)
{
	print_queue(command_q);

	return (1);
}

#include "shell.h"
#include <stdlib.h>

/**
 * exit_shell - Frees the queue and return exit code
 *
 * @q: Pointer to the queue
 * @status: exit code to exit with
 *
 * Return: See macro values
 */

void exit_shell(his_q_t *his_q, queue_t *q, int status)
{
	free_command_queue(q);
	free_history_queue(his_q);
	exit(status);
}

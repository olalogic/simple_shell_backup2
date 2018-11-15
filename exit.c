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

void exit_shell(queue_t *q, int status)
{
	if (!q)
		exit(status);
	free_command_queue(q);
	exit(status);
}

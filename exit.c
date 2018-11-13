#include "shell.h"
#include <stdlib.h>

/**
 * exit - Frees the queue and return exit code
 *
 * @q: Pointer to the queue
 *
 * Return: See macro values
 */

void exit(queue_t *q)
{
	if (!q)
		return (EXIT_FAILURE);

	free_command_queue(q);
	return (EXIT_SUCCESS);
	exit();
}

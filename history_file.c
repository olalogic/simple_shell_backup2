#include "shell.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/**
 * write_queue_to_file - Writes history to file upon exit
 *
 * @q: Pointer to the queue
 *
 * Return: none
 */

void write_queue_to_file(his_q_t *q)
{
	int check_status = 0, open_fd = 0;
	char *fn = ".simple_shell_history";
	char *home = _getenv("HOME"); /* CANT USE GETENV */

	if (!q)
	{
		printf("NO HISTORY\n");
		return;
	}

	/* TODO: CAT HOME W/ FN */
	printf("write_queue_to_file home got:%s\n", home);
	(void)home;

	open_fd = open(fn, O_CREAT | O_RDWR, 0600);
	if (open_fd < 0)
	{
		printf("FILE NOT OPENED\n");
		return;
	}

	write_h_queue(q, open_fd);

	check_status = close(open_fd);
	if (check_status < 0)
		return;

	printf("write_queue_to_file success\n");
}

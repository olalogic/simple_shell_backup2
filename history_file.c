#include "shell.h"
#include <fcntl.h>
#include <stdio.h>

/**
 * write_queue_to_file - Writes history to file upon exit
 *
 * @q: Pointer to the queue
 *
 * Return: none
 */

void write_queue_to_file(his_q_t *q)
{
	int s_command = 0, s_number = 0, check_write = 0, total = 0, i, j, k;
	int str_ind = 0;
	char *home = getenv("HOME"); /* CANT USE GETENV */
	char *fn = ".simple_shell_history";
	char *priority_n_s = NULL, *node_buffer = NULL;
	history_t *temp = NULL;

	if (!q)
	{
		printf("NO HISTORY");
		return;
	}
	temp = q->front;


	check_open = open(fn, O_CREAT | O_RDWR, 0600);
	if (check_open < 0)
	{
		printf("FILE NOT OPENED");
		return;
	}


	while (temp)
	{
		priority_n_s = get_int(temp->priority_number);
		if (!priority_n_s)
			return;
		s_number = _strlen(priority_n_s);
		s_command = _strlen(temp->command);
		total = s_number + s_command + 5;
		str_index = s_number + 3;
		node_buffer = malloc(sizeof(char) * total);
		if (!node_buffer)
			return;
		i = j = k = 0;
		while (i < total)
		{
			if (i == 0)
				node_buffer[i] = '\t';
			else if (i < s_number + 1)
				node_buffer[i] = priority_n_s[j++];
			else if (i < str_index)
				node_buffer[i] = temp->command[k++];
			else
				node_buffer[i] = '\n';
			i++;
		}
		node_buffer[i] = '\0';
		free(priority_n_s);
		check_write = write(check_open, node_buffer, total);
		if (check_write < 0)
			return;
		strncpy(check_open, home, total); /* CANT USE STRNCPY */
		free(node_buffer);
		temp = temp->next;
	}
	check_close = close(check_open);
	if (check_close < 0)
		return;

	printf("Success");
}

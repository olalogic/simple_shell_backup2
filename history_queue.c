#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * create_h_queue - Creates the queue of nodes
 *
 * Return: Address of node
 */

his_q_t *create_h_queue()
{
	his_q_t *q = malloc(sizeof(his_q_t));

	if (!q)
		return (NULL);

	q->front = q->rear = NULL;
	return (q);
}

/**
 * h_enqueue - Adds new node to the front
 *
 * @q: Pointer to queue
 *
 * @command: Points to the first char
 * in the stream
 *
 * Return: (0) failure (1) success
 */

int h_enqueue(his_q_t *q, char *command)
{
	int p_no = 0;

	history_t *new_node;

	if (q->rear)
		p_no = q->rear->priority_number + 1;

	new_node = create_history_t(command, p_no);
	if (!new_node)
		return (0);

	if (!q->rear)
	{
		
		q->front = new_node;
		q->rear = new_node;
		return (1);
	}

	q->rear->next = new_node;
	q->rear = new_node;
	return (1);
}


/**
 * h_dequeue - Removes the node after executed
 *
 * @q: Pointer to the history queue
 *
 * Return: Node that was removed
 */

history_t *h_dequeue(his_q_t *q)
{
	history_t *old_node = NULL;

	if (!q->front)
		return (NULL);

	old_node = q->front;
	q->front = q->front->next;

	if (!q->front)
		q->rear = NULL;

	return (old_node);
}

/* ONLY USED FOR DEBUGGING */
/**
 * print_h_queue - Prints the contents of the
 * history queue
 *
 * @q: Pointer to the queue
 *
 * Return: none
 */

void print_h_queue(his_q_t *q)
{
	history_t *temp = NULL;

	if (!q)
		printf("NO HISTORY");

	temp = q->front;

	while (temp)
	{
		printf("%d\n", temp->priority_number);
		printf("%c\n", temp->command);
		temp = temp->next;
		printf("\nENDOFHISTORY\n");
	}
}

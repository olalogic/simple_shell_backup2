#ifndef _SHELL_H_
#define _SHELL_H_

/**
 * struct command_s - Structure of each node
 *
 * @prev_valid: Check if previous command
 * was successful
 *
 * @separator: Used for character that
 * that separates each command
 *
 * @command: Points to the first char
 * in the stream
 *
 * @next: Address of next node
 *
 */
typedef struct command_s
{
	int prev_valid;

	char separator;
	char **command;
	command_t *next;
} command_t;

/**
 * struct queue_s - Structure of queue
 *
 * @front: Pointer to the first node
 *
 * @rear: Pointer to the front+1 node
 *
 */

typedef struct queue_s
{
	command_t *front, *rear;
} queue_t;

void free_token_list(char **tokens);
void free_command_queue(command_t **head);
command_t *create_command(char separator, char **command);
char **strtow(char *str);
int is_delim(char ch, char *delims);
queue_t *create_queue();
int enqueue(queue_t *q, char separator, char **command);
command_t dequeue(queue_t *q);

#endif /* _SHELL_H_ */

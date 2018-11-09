#ifndef _SHELL_H_
#define _SHELL_H_

/**
 * struct commands - Structure of each node
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

typedef struct commands
{
	int prev_valid;

	char separator;
	char *command;
	command_t *next;
} command_t;

#endif /* _SHELL_H_ */

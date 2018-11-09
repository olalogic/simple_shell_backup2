#ifndef _SHELL_H_
#define _SHELL_H_

typedef struct commands
{
	int prev_valid;

	char separator;
	char *command;
	command_t *next;
} command_t;

#endif /* _SHELL_H_ */

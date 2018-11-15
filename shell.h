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
	struct command_s *next;
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

/* main functionality */
int start_shell(void);
queue_t *parse_string(char *input_str);
int execute_commands(queue_t *command_q, char *envp[]);

/* free memory */
void free_token_list(char **tokens);
void free_command_queue(queue_t *command_q);
void free_command(command_t *command);

/* build the queue of commands */
command_t *create_command(char separator, char **command);
char **strtow(char *str);
int is_delim(char ch, char *delims);
queue_t *create_queue();

/* using our queue */
int enqueue(queue_t *q, char separator, char **command);
command_t *dequeue(queue_t *q);
void print_queue(queue_t *q);

/* custom functions for custom commands */
void exit_shell(queue_t *q, int status);
int print_env(char *envp[]);

/* handling signals */
void signal_handler(int sig_no);
int register_signal_handlers(void);

/* custom stdlib */
int _atoi(char *str);

/* print errors */
void print_no_file_error(void);
void print_signal_reg_error(void);
void print_prompt(void);
void print_newline(void);

#endif /* _SHELL_H_ */

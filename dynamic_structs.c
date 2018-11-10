#include "shell.h"
/**
 * create_command - creates space for command structure containing data passed
 * @command: array of pointers to tokens used in command including command
 * itself.
 * @separator: the character separator, either ';', '|', '&', or '\0'(none)
 */
command_t *create_command(char separator, char **command)
{
	command_t *ret;

	ret = malloc(sizeof(command_t));
	if (!ret)
		return (NULL);
	ret->separator = separator;
	ret->command = command;
	ret->prev_valid = 1; /* default validity of previous command is true */
	ret->next = NULL;
	return (ret);
}
/**
 * free_command_list - frees a linked list of command_t's
 * @head: double pointer to the head of the linked list
 *
 * Return: always void.
 */
void free_command_list(command_t **head)
{
	if (head == NULL)
		return;
	while (*head)
	{
		free_token_list((*head)->command);	
		free(*head);
		*head = (*head)->next;
	}
	head = NULL;
}
/**
 * free_token_list - frees an array of tokens previously malloced
 * @tokens: 2D array of tokens
 *
 * Return: always void.
 */
void free_token_list(char **tokens)
{
	if (!tokens)
		return;
	while (tokens)
	{
		if (tokens[i])
			free(tokens[i]);
		i++;
	}
	free(tokens);
}

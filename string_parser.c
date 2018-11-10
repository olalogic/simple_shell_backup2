#include "shell.h"

/**
 * parse_string - Writes tokens to a linked list
 *
 * @str: Pointer to the token stream
 *
 * Return: NULL (failure) head (success)
 */

command_t *parse_string(char *str)
{
	char **raw_tokens;

	command_t *head = NULL;

	if (!str)
		return (NULL);

	raw_tokens = strtow(str);

	if (!raw_tokens)
		return (NULL);

	/* currently writes everything to one node*/
	/* one command functionality */

	head = create_command('\0', raw_tokens);

	if (!head)
	{
		free_token_list(raw_tokens);
		return (NULL);
	}

	return (head);
}

#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_env - Stores and prints the `env`
 *
 * @envp: Double pointer to tokens
 *
 * Return: 0 (failure) 1 (success)
 */

int print_env(char *envp[])
{
	int i, j, char_ctr, buf_ind, check_write;

	char *buffer;

	i = j = char_ctr = buf_ind = check_write = 0;


	if (!envp)
		return (0);

	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
			j++;

		char_ctr += j + 1;
		i++;
	}

	buffer = malloc(sizeof(char) * char_ctr + 1);
	if (!buffer)
		return (0);

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
			buffer[buf_ind++] = envp[i][j++];

		buffer[buf_ind++] = '\n';
		i++;
	}

	check_write = write(STDOUT_FILENO, buffer, char_ctr);
	free(buffer);
	if (check_write < 0)
		return (0);

	return (1);
}

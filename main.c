#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Starts the shell CLI
 *
 * @argc: Number of CLI args (index starts at 1)
 *
 * @argv: Pointer to the first CLI arg
 *
 * Return: 0 (success)
 */

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	return (start_shell());
}

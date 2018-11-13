#include "shell.h"
#include <stdio.h>

/**
 * print_no_file_error - prints the no file error message to STDOUT
 *
 * Return: always void.
 */
void print_no_file_error(void)
{
	write(STDOUT_FILENO, "No such file or directory\n", 26);
}

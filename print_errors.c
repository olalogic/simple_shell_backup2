#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * print_no_file_error - prints the no file error message to STDOUT
 *
 * Return: always void.
 */
void print_no_file_error(void)
{
	write(STDOUT_FILENO, "\nNo such file or directory\n", 27);
}

/**
 * print_signal_reg_error - prints the sig registry error message to STDOUT
 *
 * Return: always void.
 */
void print_signal_reg_error(void)
{
	write(STDOUT_FILENO, "Failed to register signals in kernal\n", 37);
}

/**
 * print_newline - prints a newline character to stdout
 *
 * Return: always void.
 */
void print_newline(void)
{
	write(STDOUT_FILENO, "\n", 1);
}

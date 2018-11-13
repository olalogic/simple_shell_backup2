#include "shell.h"
#include <stdio.h>
#include <signal.h>

/**
 * signal_handler - Prevents CTRL-C from interrupting shell
 *
 * @sig_no: Holds the signal number
 *
 * Return: none
 */

void signal_handler(int sig_no)
{
	if (sig_no == SIGINT)
		print_no_file_error();
}	

#include "shell.h"
#include <stdio.h>

void print_no_file_error(void)
{
	write(STDOUT_FILENO, "No such file or directory\n", 26);
}

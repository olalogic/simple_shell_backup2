#include <stdlib.h>

/**
 * sparser - Groups pointers to words
 * to be put into separate nodes of SLL
 *
 * @str: Pointer to first word
 *
 * Return: Pointer to first delim char
 */

char **sparser(char *str)
{
	int i = 0;
	int n;

	char **start = strtow(str[i]);
	char **marker;

	/* check each word for delimitor char */
	while (start[i] != NULL)
	{
		n = 0;

		/* loop through pointer set */
		while (start[i][n] != '\0');
		{
			/* write word to node */
			/* set the nodes specifier */
			n++;
		}

		/* if next words first char is not a delim */
		if (start[i + 1][n] != DELIMS)
		{
			/* write that word to node prepended by space */
			/* to node */
		}

		else
			marker = start[i][n];

		/* set marker to first char of next word */
		i++;
	}
	return (marker);
}

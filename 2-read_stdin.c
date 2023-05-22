#include "shell.h"
/**
 * read_stdin - read a line from the stdin.
 * Return: pointer points to the line.
 */
char *read_stdin(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	int len;

	len = getline(&lineptr, &n, stdin);
	if (len == EOF)
	{
		/* in case of “end of file” condition (Ctrl+D)*/
		write(STDOUT_FILENO, "\n", 1);
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	if (len == -1)
	{
		perror("getline: ");
		exit(EXIT_FAILURE);
	}

	if (*lineptr == '\n')
	{
		/* in case of empty line (nothing been entred)*/
		return (NULL);
	}

	return (lineptr);
}

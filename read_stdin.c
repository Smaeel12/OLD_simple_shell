#include "shell.h"
/**
 * read_stream - read a line from the stream
 * Return: pointer points to the line
 */
char *read_stdin(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	int len;
	
	len = getline(&lineptr, &n, stdin);
	if (len == EOF)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	if (len == -1)
	{
		perror("getline: ");
		exit(EXIT_FAILURE);
	}
	return (lineptr);
}

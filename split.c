#include "shell.h"
/**
 * tokeniz - Breaks a string into a sequence of tokens based on a specified delimiter.
 */
char **tokeniz(char *line)
{
	int length = 0;
	int capacity = 16;
	char **tokens = malloc(capacity * sizeof(char*));
	char *delimiters = " \n";
	char *token;

	token = strtok(line, delimiters);
	while (token != NULL)
	{
		tokens[length] = token;
		length++;
		token = strtok(NULL, delimiters);
	}
	tokens[length] = NULL;
	return (tokens);
}

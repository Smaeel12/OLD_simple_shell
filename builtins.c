#include "shell.h"
#include <ctype.h>
/**
 * end - function causes normal process termination and exit the program,
 * and write exit status on success
 * @line: command line.
 * @cmd: normal process.
 * Return: On Success nothing returned. return 3 in failure
 * as status to error() function in case of invalid exit status
 */
int end(char *line, char **cmd)
{
	if (cmd[1] != NULL)
	{
		int exit_num = atoi(cmd[1]);

		if (exit_num < 0 || (exit_num == 0 && *cmd[1] != '0'))
			return (3);
		free(cmd);
		free(line);
		exit(exit_num);
	}
	free(cmd);
	free(line);
	exit(EXIT_SUCCESS);
}
/**
 * env_print - function that Display environment variables.
 * @line: command line.
 * @cmd: the env command.
 * Return: 0 àn success.
 */
int env_print(char *line, char **cmd)
{
	int i;
	char **vars = environ;
	(void)line;

	for (i = 0; vars[i] != NULL; i++)
	{
		printf("%s\n", vars[i]);
	}
	*cmd = NULL;
	return (0);
}

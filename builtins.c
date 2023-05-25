#include "shell.h"
#include <ctype.h>
/**
 * end - function causes normal process termination and exit the program,
 * and write exit status on success
 * @cmd: normal process.
 * Return: On Success nothing returned. return 2 in failure
 * as status to error() function in case of invalid exit status
 */
int end(char **cmd)
{
	if (cmd[1] != NULL)
	{
		int exit_num = atoi(cmd[1]);

		if (exit_num == 0 && *cmd[1] != '0')
			return (2);
		free(cmd);
		exit(exit_num);
	}
	free(cmd);
	exit(EXIT_SUCCESS);
}
/**
 * env - function that Display environment variables.
 * @cmd: the env command.
 * Return: 0 àn success.
 */
int env_print(char **cmd)
{
	int count = 0;
	char **env = environ;
	char **envArray = NULL;
	int i, j;


	while (*env != NULL)
	{
		count++;
		env++;
	}
	envArray = malloc((count + 1) * sizeof(char *));
	env = environ;

	for (i = 0; i < count; i++)
	{
		envArray[i] = *env;
		env++;
	}
	envArray[count] = NULL;
	for (j = count - 1; j >= 0; j--)
		printf("%s\n", envArray[j]);

	free(envArray);
	*cmd = NULL;
	return (0);
}

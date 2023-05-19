#include "shell.h"
/**
 * interactive_mode - the program in interactive mode.
 * @running: number of commands entred.
 */
void interactive_mode(int running)
{
	char *line;
	char **cmds;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 10);

		line = read_stdin();
		if (line == NULL)
		{
			running++;
			interactive_mode(running);
		}

		cmds = tokeniz(line);
		if (cmds != NULL)
		{
			excutcmd(cmds, running);
		}

		running++;
		free(line);
		free(cmds);
	}
}

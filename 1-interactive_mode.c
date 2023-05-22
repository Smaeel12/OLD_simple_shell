#include "shell.h"
/**
 * interactive_mode - the program in interactive mode.
 */
void interactive_mode(void)
{
	char *line;
	char **cmds;
	int err_check = 0;
	int running = 1;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 10);
		line = read_stdin();
		if (line != NULL)
		{
			cmds = tokeniz(line);
			err_check = excutcmd(cmds);
			if (err_check > 0)
			{
				error(err_check, cmds, running);
			}
			free(line);
			free(cmds);
		}
		running++;
	}
}

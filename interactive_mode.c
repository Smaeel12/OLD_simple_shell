#include "shell.h"
/**
 * interactive_mode - 
 */
void interactive_mode(void)
{
	char *line;
	char **cmds;
	int running = 1;
	while (1)
	{
		write (STDOUT_FILENO, "#cisfun$ ", 10);
		line = read_stdin();
		cmds = tokeniz(line);
		if (cmds != NULL)
		{
			excutcmd(cmds, running);
		}
		running++;
	}
	free(line);
	free(cmds);
}

#include "shell.h"
/**
 * interactive_mode - 
 */
void interactive_mode(void)
{
	char *line;
	char **cmds;

	while (1)
	{
		write (STDOUT_FILENO, "#cisfun$ ", 10);
		line = read_stdin();
		cmds = tokeniz(line);
		if (cmds != NULL)
		{
			excutcmd(cmds);
		}
	}
	free(line);
	free(cmds);
}

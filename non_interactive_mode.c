#include "shell.h"
/**
 * interactive_mode - 
 */
void non_interactive_mode(void)
{
	char *line;
	char **cmds;

	while (1)
	{
		line = read_stream();
		cmds = tokeniz(line);
		excutcmd(cmds);
	}
	free(line);
	free(cmds);
}

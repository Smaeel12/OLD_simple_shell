#include "shell.h"
/**
 * non_interactive_mode - the program in the non interactive mode.
 */
void non_interactive_mode(void)
{
	char *line;
	char **cmds;
	int running = 1;

	while (1)
	{
		line = read_stream();
		cmds = tokeniz(line);
		excutcmd(cmds, running);
	}
	free(line);
	free(cmds);
}

#include "shell.h"
/**
 * non_interactive_mode - the program in the non interactive mode.
 * @progname: program name.
 */
void non_interactive_mode(char *progname)
{
	char *line = NULL;
	char **cmds;
	int err_check = 0;
	int running = 1;

	while (1)
	{
		line = read_stream();
		cmds = tokeniz(line);
		err_check = excutcmd(cmds);
		if (err_check > 0)
		{
			switch (err_check)
			{
				case 1:
					exit(2);
					break;
				case 2:
					error(progname, err_check, cmds, running);
					exit(127);
					break;
				default:
					exit(0);
					break;
			}
		}
		free(line);
		free(cmds);
	}
}
